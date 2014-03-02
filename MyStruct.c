#include "ruby.h"


typedef struct {
  char * name;
  int     age;
} MyStruct;

static void my_free(MyStruct * hdfr) {
  rb_gc_mark(hdfr->name);
}

static VALUE my_alloc(VALUE klass) {
  return Data_Wrap_Struct(klass, NULL, my_free, ruby_xmalloc(sizeof(MyStruct)));
}

static VALUE my_init(VALUE self, VALUE _name, VALUE _age) {
  MyStruct * hdfr;
  Data_Get_Struct(self, MyStruct, hdfr);

  hdfr->name = RSTRING_PTR(_name);
  hdfr->age  = NUM2INT(_age);

  return Qnil;
}

static VALUE my_toString(VALUE self) {
  char * toString;
  MyStruct * hdfr;

  Data_Get_Struct(self, MyStruct, hdfr);

  toString = (char*)malloc((sizeof(char) * (strlen(hdfr->name) + 20)));

  sprintf(toString, "%s, %d year-old", hdfr->name, hdfr->age);

  return rb_str_new2(toString);
}

void Init_MyStruct() {
  VALUE c = rb_define_class("MyStruct", rb_cObject);

  rb_define_alloc_func(c, my_alloc);
  rb_define_private_method(c, "initialize", RUBY_METHOD_FUNC(my_init), 2);
  rb_define_method(c, "to_s", RUBY_METHOD_FUNC(my_toString), 0);
}
