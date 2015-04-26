#include <nan.h>
#include "create_subvolume.hh"
#include "create_snapshot.hh"

using v8::FunctionTemplate;
using v8::Handle;
using v8::Object;
using v8::String;

void InitAll(Handle<Object> exports) {
  exports->Set(NanNew<String>("create_snapshot"),
    NanNew<FunctionTemplate>(CreateSnapshot)->GetFunction());

  exports->Set(NanNew<String>("create_subvolume"),
    NanNew<FunctionTemplate>(CreateSubvolume)->GetFunction());
}

NODE_MODULE(btrfs, InitAll)
