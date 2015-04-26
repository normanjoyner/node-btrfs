{
  "targets": [
    {
      "target_name": "btrfs",
      "sources": [
        "src/btrfs.cc",
        "src/snapshot.cc",
        "src/btrfs_utils.cc"
      ],
      "include_dirs" : [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}
