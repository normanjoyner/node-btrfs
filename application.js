var pkg = require([__dirname, "package"].join("/"));
var btrfs = require([__dirname, "build", "Release", "btrfs"].join("/"));

btrfs.version = pkg.version;

module.exports = btrfs;
