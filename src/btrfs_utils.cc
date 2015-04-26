#include "btrfs_utils.hh"

#include <btrfs/kerncompat.h>
#include <btrfs/send-stream.h>

#include <nan.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <libgen.h>
#include <stdio.h>

/**
 * Open a directory and return the file descriptor or -1 for error.
 */
int open_dir(const char *fname, DIR **dirstream)
{
    int fd;

    *dirstream = opendir(fname);
    if (!*dirstream) {
        return -1;
    }

    fd = dirfd(*dirstream);

    if (fd < 0) {
        if (*dirstream) {
            closedir(*dirstream);
        }
        return -1;
    }

    return fd;
}

/**
 * Create a snapshot of a btrfs subvolume.
 */
int create_snapshot(const char subvol[BTRFS_VOL_NAME_MAX], const char dst[PATH_MAX], struct create_snapshot_options options, char *err)
{

    int res;
    int fd_dst;
    struct btrfs_ioctl_vol_args_v2 args;
    DIR *dir1;
    DIR *dir2;

    char *dst_dup1 = strdup(dst);
    char *dst_dup2 = strdup(dst);
    char *dst_dir = dirname(dst_dup1);
    char *snapshot_name = basename(dst_dup2);

    args.fd = open_dir(subvol, &dir1);
    if (args.fd < 0) {
        sprintf(err, "Cannot stat %s", subvol);
        return -1;
    }

    fd_dst = open_dir(dst_dir, &dir2);
    if (fd_dst < 0) {
        sprintf(err, "Cannot stat %s", dst_dir);
        return -1;
    }

    if (options.readonly) {
        args.flags |= BTRFS_SUBVOL_RDONLY;
    }

    // create the snapshot
    strncpy(args.name, snapshot_name, BTRFS_VOL_NAME_MAX);
    res = ioctl(fd_dst, BTRFS_IOC_SNAP_CREATE_V2, &args);
    if (res < 0) {
        sprintf(err, "%s", strerror(errno));
        return -1;
    }

    // cleanup
    closedir(dir1);
    closedir(dir2);

    return 0;
}

/**
 *  Send a subvolume
 */
int send(const char subvol[BTRFS_VOL_NAME_MAX])
{
    return 0; // went well
}

/**
 * Restore a snapshot of a btrfs subvolume.
 */
int restore_snapshot()
{
    return 0; // went well
}

