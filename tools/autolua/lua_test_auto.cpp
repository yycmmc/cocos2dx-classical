#include "lua_test_auto.h"
#include "test.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"

int lua_test_SimpleNativeClass_createTestR10e(lua_State* tolua_S) {
    // variables
    int argc = 0;
    bool ok = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

    // validate the top is our desired object type
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S, 1,"SimpleNativeClass", 0, &tolua_err)) {
        tolua_error(tolua_S, "#ferror in function 'lua_test_SimpleNativeClass_createTestR10e'.", &tolua_err);
        return 0;
    }
#endif

    // get argument count
    argc = lua_gettop(tolua_S) - 1;

    // if argument count matched, call
    if (argc == 1) {
        // arguments declaration
        cocos2d::CCNode* arg0;

        // convert lua value to desired arguments
        ok &= luaval_to_object<cocos2d::CCNode>(tolua_S, 2, "CCNode", &arg0);

        // if conversion is not ok, print error and return
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_test_SimpleNativeClass_createTestR10e'", nullptr);
            return 0;
        }

        // call function
        cocos2d::SimpleNativeClass* ret = cocos2d::SimpleNativeClass::createTestR10e(arg0);
        object_to_luaval<cocos2d::SimpleNativeClass>(tolua_S, "SimpleNativeClass", (cocos2d::SimpleNativeClass*)ret);
        return 1;
    }

    // if argument count matched, call
    if (argc == 2) {
        // arguments declaration
        cocos2d::CCNode* arg0;
        cocos2d::CCNode* arg1;

        // convert lua value to desired arguments
        ok &= luaval_to_object<cocos2d::CCNode>(tolua_S, 2, "CCNode", &arg0);
        ok &= luaval_to_object<cocos2d::CCNode>(tolua_S, 3, "CCNode", &arg1);

        // if conversion is not ok, print error and return
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_test_SimpleNativeClass_createTestR10e'", nullptr);
            return 0;
        }

        // call function
        cocos2d::SimpleNativeClass* ret = cocos2d::SimpleNativeClass::createTestR10e(arg0, arg1);
        object_to_luaval<cocos2d::SimpleNativeClass>(tolua_S, "SimpleNativeClass", (cocos2d::SimpleNativeClass*)ret);
        return 1;
    }

    // if to here, means argument count is not correct
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SimpleNativeClass:createTestR10e", argc, 1);
    return 0;
}

int lua_register_test_SimpleNativeClass(lua_State* tolua_S) {
    tolua_usertype(tolua_S, "SimpleNativeClass");
    tolua_cclass(tolua_S, "SimpleNativeClass", "SimpleNativeClass", "", nullptr);

    // register module
    tolua_beginmodule(tolua_S, "SimpleNativeClass");
        tolua_function(tolua_S, "createTestR10e", lua_test_SimpleNativeClass_createTestR10e);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::SimpleNativeClass).name();
    g_luaType[typeName] = "SimpleNativeClass";
    g_typeCast["SimpleNativeClass"] = "SimpleNativeClass";
    return 1;
}

TOLUA_API int register_all_test(lua_State* tolua_S) {
	tolua_open(tolua_S);
	
	tolua_module(tolua_S, nullptr, 0);
	tolua_beginmodule(tolua_S, nullptr);

	lua_register_test_SimpleNativeClass(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

