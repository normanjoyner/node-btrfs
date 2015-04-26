{
  "targets": [
    {
      "target_name": "btrfs",
      "sources": [
        "btrfs.cc",
        "snapshot.cc",
        "btrfs_utils.cc"
      ],
      "include_dirs" : [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}
