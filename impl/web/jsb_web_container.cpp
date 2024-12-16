#include "jsb_web_container.h"

#include "jsb_web_typedef.h"
#include "jsb_web_isolate.h"

namespace v8
{
    Local<Array> Array::New(Isolate* isolate, int length)
    {
        return Local<Array>(Data(isolate, isolate->push_steal(JS_NewArray(isolate->ctx()))));
    }

    uint32_t Array::Length() const
    {
        JSContext* ctx = isolate_->ctx();
        const JSValue val = isolate_->stack_val(stack_pos_);
        const JSValue len = JS_GetProperty(ctx, val, jsb::impl::JS_ATOM_length);
        if (JS_IsException(len))
        {
            return 0;
        }

        uint32_t rval;
        JS_ToUint32(ctx, &rval, len);
        JS_FreeValue(ctx, len);
        return rval;
    }

    MaybeLocal<Map> Map::Set(Local<Context> context, Local<Value> key, Local<Value> value)
    {
        JSContext* ctx = isolate_->ctx();

        const jsb::impl::BrowserJS::Atom key_atom(ctx, (JSValue) key);
        if (key_atom == JS_ATOM_NULL)
        {
            return MaybeLocal<Map>();
        }
        JS_SetProperty(ctx, (JSValue) *this, key_atom, JS_DupValue(ctx, (JSValue) value));

        return MaybeLocal<Map>(Data(isolate_, stack_pos_));
    }

    Local<Map> Map::New(Isolate* isolate)
    {
        return Local<Array>(Data(isolate, isolate->push_map()));
    }

}
