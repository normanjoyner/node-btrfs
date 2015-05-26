var assert = require("assert");
var btrfs = require([__dirname, "..", "application"].join("/"));

module.exports = {

    start: function(){
        describe("delete_subvolume", function(){
            it("should delete a btrfs subvolume", function(fn){
                btrfs.delete_subvolume("/mnt/btrfs/test_delete_subvolume", fn);
            });
        });
    }

}
