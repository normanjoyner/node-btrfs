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
