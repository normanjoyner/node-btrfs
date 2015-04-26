#include <nan.h>
#include "btrfs_utils.hh"
#include "snapshot.hh"

using v8::Function;
using v8::Local;
using v8::Null;
using v8::Number;
using v8::String;
using v8::Object;
using v8::Boolean;
using v8::Value;

class SnapshotWorker: public NanAsyncWorker {
    public:
        SnapshotWorker(NanCallback *callback, std::string sourcePath, std::string destinationPath, struct create_snapshot_options options)
            : NanAsyncWorker(callback), sourcePath(sourcePath), destinationPath(destinationPath), options(options) {}
        ~SnapshotWorker() {}

        void Execute () {
            char err[1024];
            int result = create_snapshot(sourcePath.c_str(), destinationPath.c_str(), options, err);
            if(result < 0) {
                SetErrorMessage(err);
            }
        }

        void HandleOKCallback () {
            NanScope();

            Local<Value> argv[] = {
                NanNull()
            };

            callback->Call(1, argv);
        }

    private:
        std::string sourcePath;
        std::string destinationPath;
        struct create_snapshot_options options;
};

NAN_METHOD(CreateSnapshot) {
    NanScope();

    String::Utf8Value source(args[0]->ToString());
    std::string sourcePath = std::string(*source);
    String::Utf8Value destination(args[1]->ToString());
    std::string destinationPath = std::string(*destination);

    Local<Object> options = args[2]->ToObject();
    int readonly = (options->Has(v8::String::NewSymbol("readonly")) ? (float)options->Get(v8::String::NewSymbol("readonly"))->IntegerValue() : 0);
    struct create_snapshot_options opts;
    opts.readonly = readonly;

    NanCallback *callback = new NanCallback(args[3].As<Function>());

    NanAsyncQueueWorker(new SnapshotWorker(callback, sourcePath, destinationPath, opts));
    NanReturnUndefined();
}
