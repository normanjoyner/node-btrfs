btrfs
==============

##About

###Description
A btrfs library for nodejs applications

###Author
ContainerShip Developers - developers@containership.io

##Getting Started

###Installation
`npm install btrfs`

###Usage
####create_subvolume
```javascript
var btrfs = require("btrfs");
btrfs.create_subvolume("/mnt/btrfs/subvolume", function(err){
    if(err)
        throw err;
});
```

####delete_subvolume
```javascript
var btrfs = require("btrfs");
btrfs.delete_subvolume("/mnt/btrfs/subvolume", function(err){
    if(err)
        throw err;
});
```

####create_snapshot
```javascript
var btrfs = require("btrfs");
btrfs.create_snapshot("/mnt/btrfs/subvolume", "/mnt/btrfs/snapshot", { readonly: true }, function(err){
    if(err)
        throw err;
});
```

##Contributing
Pull requests and issues are encouraged!
