var assert = require("assert");
var btrfs = require([__dirname, "..", "application"].join("/"));

module.exports = {

    start: function(){
        describe("create_subvolume", function(){
            it("should create a btrfs subvolume", function(fn){
                btrfs.create_subvolume("/mnt/btrfs/test_create_subvolume", fn);
            });

            after(function(fn){
                btrfs.delete_subvolume("/mnt/btrfs/test_create_subvolume", fn);
            });
        });
    }

}
