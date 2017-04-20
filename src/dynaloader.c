/*
** mrb_dynaloader.c - DynaLoader class
**
** Copyright (c) Uchio Kondo 2017
**
** See Copyright Notice in LICENSE
*/
#define _GNU_SOURCE
#include <dlfcn.h>
#include <errno.h>
#include <string.h>

#include <mruby.h>
#include <mruby/data.h>
#include <mruby/error.h>

#define DONE mrb_gc_arena_restore(mrb, 0);

typedef struct {
  void *dl_handler;
} mrb_dl_handler_data;

typedef struct {
  void *(*sym)(void);
} mrb_dl_sym_data0;

static const struct mrb_data_type mrb_dl_handler_data_type = {
    "mrb_dl_handler_data", mrb_free,
};

static mrb_value mrb_dynaloader_init(mrb_state *mrb, mrb_value self)
{
  mrb_dl_handler_data *data;
  char *str;

  mrb_get_args(mrb, "z", &str);
  data = (mrb_dl_handler_data *)mrb_malloc(mrb, sizeof(mrb_dl_handler_data));
  data->dl_handler = dlopen(str, RTLD_NOW);
  if (!data->dl_handler) {
    mrb_raisef(mrb, E_RUNTIME_ERROR, "dlopen failed: %s", strerror(errno));
  }
  DATA_PTR(self) = data;

  dlerror(); /* cleanup */
  return self;
}

static mrb_value mrb_dynaloader_handler_ptr_str(mrb_state *mrb, mrb_value self)
{
  mrb_dl_handler_data *data = DATA_PTR(self);
  char dest[16];

  snprintf(dest, 16, "%p", data->dl_handler);

  return mrb_str_new_cstr(mrb, dest);
}

void mrb_mruby_dynaloader_gem_init(mrb_state *mrb)
{
  struct RClass *dynaloader;
  dynaloader = mrb_define_class(mrb, "DynaLoader", mrb->object_class);
  mrb_define_method(mrb, dynaloader, "initialize", mrb_dynaloader_init, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, dynaloader, "handler_ptr_str", mrb_dynaloader_handler_ptr_str, MRB_ARGS_NONE());
  DONE;
}

void mrb_mruby_dynaloader_gem_final(mrb_state *mrb)
{
}
