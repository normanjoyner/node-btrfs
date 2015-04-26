var _ = require("lodash");

var tests = {
    create_subvolume: require([__dirname, "create_subvolume"].join("/")),
    delete_subvolume: require([__dirname, "delete_subvolume"].join("/")),
    create_snapshot: require([__dirname, "create_snapshot"].join("/"))
}

var run_tests = function(){
    _.each(tests, function(test, test_name){
        test.start();
    });
}

run_tests();
