#ifndef ASSISTENTE_HEADER
#define ASSISTENTE_HEADER

#include <gtk/gtk.h>

enum{
  APRESENTACAO_PAGE,
  BD_CONFIG_PAGE,
  EMPRESA_CONFIG_PAGE,
  CONCLUSAO_PAGE
};

struct _bd_config{
  gchar *addr;
  gchar *user;
  gchar *pass;
};

struct _assistente{
  GtkWidget *wnd;

  GtkWidget *init_page;
  GtkWidget *bdconfig_page;
  GtkWidget *finish_page;

  struct _bd_config *bd_config;
};

struct _assistente *assistente;

int assistente_init();

int validate_dbpage();

struct _assistente *assistente_render_wnd();

int assistente_get_server_addr(GtkEntry *addr_entry, gpointer next_widget);

int assistente_get_server_user(GtkEntry *user_entry, gpointer next_widget);

int assistente_get_server_pass(GtkEntry *pass_entry, gpointer next_widget);

GtkWidget *assistente_get_page(int page_num);

void libera_dbpage();

void bloqueia_dbpage();

#endif
