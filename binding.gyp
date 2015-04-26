{
  "targets": [
    {
      "target_name": "btrfs",
      "sources": [
        "src/btrfs.cc",
        "src/create_subvolume.cc",
        "src/delete_subvolume.cc",
        "src/create_snapshot.cc",
        "src/btrfs_utils.cc"
      ],
      "include_dirs" : [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}
