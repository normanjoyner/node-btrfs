var assert = require("assert");
var btrfs = require([__dirname, "..", "application"].join("/"));

module.exports = {

    start: function(){
        describe("delete_subvolume", function(){
            before(function(fn){
                btrfs.create_subvolume("/mnt/btrfs/test_delete_subvolume", fn);
            });

            it("should delete a btrfs subvolume", function(fn){
                btrfs.delete_subvolume("/mnt/btrfs/test_delete_subvolume", fn);
            });
        });
    }

}
