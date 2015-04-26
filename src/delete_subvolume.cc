#include <nan.h>
#include "btrfs_utils.hh"
#include "delete_subvolume.hh"

using v8::Function;
using v8::Local;
using v8::Null;
using v8::Number;
using v8::String;
using v8::Object;
using v8::Boolean;
using v8::Value;

class DeleteSubvolumeWorker: public NanAsyncWorker {
    public:
        DeleteSubvolumeWorker(NanCallback *callback, std::string destinationPath)
            : NanAsyncWorker(callback), destinationPath(destinationPath) {}
        ~DeleteSubvolumeWorker() {}

        void Execute () {
            char err[1024];
            int result = delete_subvolume(destinationPath.c_str(), err);
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
        std::string destinationPath;
};

NAN_METHOD(DeleteSubvolume) {
    NanScope();

    String::Utf8Value destination(args[0]->ToString());
    std::string destinationPath = std::string(*destination);

    NanCallback *callback = new NanCallback(args[1].As<Function>());

    NanAsyncQueueWorker(new DeleteSubvolumeWorker(callback, destinationPath));
    NanReturnUndefined();
}
