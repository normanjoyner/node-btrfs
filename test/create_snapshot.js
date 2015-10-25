var assert = require("assert");
var btrfs = require([__dirname, "..", "application"].join("/"));

module.exports = {

    start: function(){
        describe("create_snapshot", function(){
            before(function(fn){
                btrfs.create_subvolume("/mnt/btrfs/test_create_snapshot", fn);
            });

            it("should create a btrfs snapshot", function(fn){
                btrfs.create_snapshot("/mnt/btrfs/test_create_snapshot", "/mnt/btrfs/newly_created_snapshot", { readonly: true }, fn);
            });
        });
    }

}
