#ifndef BTRFS_UTILS_H
#define BTRFS_UTILS_H

#include <btrfs/ioctl.h>
#include <linux/limits.h>

struct create_snapshot_options {
    bool readonly;
};

int create_subvolume(const char subvol[BTRFS_VOL_NAME_MAX], char *err);
int create_snapshot(const char subvol[BTRFS_VOL_NAME_MAX], const char dst[PATH_MAX], struct create_snapshot_options options, char *err);

#endif /* BTRFS_UTILS_H */
