#ifndef GODOTJS_QUICKJS_ARRAY_H
#define GODOTJS_QUICKJS_ARRAY_H
#include "jsb_quickjs_object.h"

namespace v8
{
    class Array : public Object
    {
    public:
        uint32_t Length() const;

        static Local<Array> New(Isolate* isolate, int length = 0);
    };

    class Map : public Object
    {
    public:
        MaybeLocal<Map> Set(Local<Context> context,
                            Local<Value> key,
                            Local<Value> value);

        static Local<Map> New(Isolate* isolate);
    };
}
#endif
