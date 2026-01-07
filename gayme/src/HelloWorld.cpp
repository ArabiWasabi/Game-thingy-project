#include "helloWorld.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/engine.hpp>

using namespace godot;

void HelloWorld::_bind_methods() 
{
    ClassDB::bind_method(D_METHOD("set_speed"), &HelloWorld::set_speed);
    ClassDB::bind_method(D_METHOD("get_speed"), &HelloWorld::get_speed);

    ClassDB::add_property("HelloWorld",PropertyInfo(Variant::FLOAT,"speed"), "set_speed", "get_speed");

    ADD_SIGNAL(MethodInfo("hello_world_signal", PropertyInfo(Variant::STRING, "data")));
}

HelloWorld::HelloWorld() 
{
    if(Engine::get_singleton()->is_editor_hint()) 
    { 
        set_process_mode(Node::ProcessMode::PROCESS_MODE_DISABLED);
    }
    UtilityFunctions::print("Hello, World from C++!");
    set_process(true);
}

HelloWorld::~HelloWorld() 
{

}

void HelloWorld::hello_world(String words) 
{
    UtilityFunctions::print(words);
    emit_signal("hello_world_signal", "data!");
}

void HelloWorld::set_speed(const double p_speed) 
{
    this->speed = p_speed;
    UtilityFunctions::print("The speed is now idk");
}
double HelloWorld::get_speed() const 
{
    return speed;
}

void HelloWorld::_process(double delta) 
{
    UtilityFunctions::print("Hello from process!");
}