var assert = require("assert");
var btrfs = require([__dirname, "..", "application"].join("/"));

module.exports = {

    start: function(){
        describe("create_snapshot", function(){
            it("should create a btrfs snapshot", function(fn){
                btrfs.create_snapshot("/mnt/btrfs/testvol", "/mnt/btrfs/testsnapshot", { readonly: true }, fn);
            });
        });
    }

}
