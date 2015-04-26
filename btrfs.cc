#include <nan.h>
#include "snapshot.hh"

using v8::FunctionTemplate;
using v8::Handle;
using v8::Object;
using v8::String;

void InitAll(Handle<Object> exports) {
  exports->Set(NanNew<String>("create_snapshot"),
    NanNew<FunctionTemplate>(CreateSnapshot)->GetFunction());
}

NODE_MODULE(btrfs, InitAll)
