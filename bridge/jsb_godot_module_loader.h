#ifndef GODOTJS_GODOT_MODULE_LOADER_H
#define GODOTJS_GODOT_MODULE_LOADER_H

#include "jsb_module_loader.h"

namespace jsb
{
    // a lazy loader for Godot classes (and singletons/constants)
    class GodotModuleLoader : public IModuleLoader
    {
    public:
        virtual ~GodotModuleLoader() override = default;

        virtual bool load(Environment* p_env, JavaScriptModule& p_module) override;

    private:
        v8::Local<v8::Object> _get_loader_proxy(Environment* p_env);
        v8::Local<v8::Value> _type_post_process(v8::Isolate* isolate, const v8::Local<v8::Context>& context, const StringName& p_type_name, const v8::Local<v8::Value>& p_val);

        v8::Global<v8::Object> loader_;

    };

}

#endif
