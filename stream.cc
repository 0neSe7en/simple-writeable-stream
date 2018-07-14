#include <napi.h>
#include <iostream>

#define EXPORT_METHOD(NAME, FUNC) \
     exports.Set(Napi::String::New(env, #NAME), Napi::Function::New(env, FUNC));

#define STATUS Napi::Number::New(info.Env(), r);

Napi::Value Write(const Napi::CallbackInfo& info) {
    void* buffer = info[0].As<Napi::Buffer<uint8_t >>().Data();
    size_t length = info[0].As<Napi::Buffer<uint8_t >>().Length();
    std::cout << "length:" << length << std::endl;
//    std::string ch_name = info[0].As<Napi::String>().ToString();
//    int remain = speaker.Write(buffer, static_cast<int32_t>(length), ch_name);
    return Napi::Number::New(info.Env(), length);
}

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
    EXPORT_METHOD(write, Write);
    return exports;
}

NODE_API_MODULE(stream, InitAll)
