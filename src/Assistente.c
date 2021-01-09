#include "Assistente.h"

#include "Pages/apresentacao.h"
#include "Pages/bd_config.h"
#include "Pages/conclusao.h"

void libera_dbpage(){
  gtk_assistant_set_page_complete (GTK_ASSISTANT(assistente->wnd), assistente->bdconfig_page, TRUE);
}


void bloqueia_dbpage(){
  gtk_assistant_set_page_complete (GTK_ASSISTANT(assistente->wnd), assistente->bdconfig_page, FALSE);
}

int validate_dbpage(GtkWidget *entry, gpointer popover){

  const gchar *text = gtk_entry_get_text(GTK_ENTRY(entry));
  if(!strlen(text)){
    if(popover){
      GtkWidget *box = gtk_bin_get_child(popover);
      if(box)
        gtk_widget_destroy(box);

      box = gtk_box_new(0,0);
      GtkWidget *msg = gtk_label_new("Preencha o campo");
      gtk_box_pack_start(GTK_BOX(box), msg,0,0,5);
      gtk_container_add(GTK_CONTAINER(popover), box);
      gtk_popover_set_modal(popover,TRUE);
      gtk_widget_show_all(popover);
      gtk_popover_popup(popover);
    }
    bloqueia_dbpage();
    return 1;
  }

  if(!assistente->bd_config->addr || !strlen(assistente->bd_config->addr)){
    bloqueia_dbpage();
    return 1;
  }

  if(!assistente->bd_config->user || !strlen(assistente->bd_config->user)){
    bloqueia_dbpage();
    return 1;
  }

  if(!assistente->bd_config->pass || !strlen(assistente->bd_config->pass)){
    bloqueia_dbpage();
    return 1;
  }

  gtk_assistant_set_page_complete (GTK_ASSISTANT(assistente->wnd), assistente->bdconfig_page, TRUE);
  return 0;
}

int assistente_get_server_addr(GtkEntry *addr_entry, gpointer next_widget){

  const gchar *addr = gtk_entry_get_text(GTK_ENTRY(addr_entry));
  if(!strlen(addr)){
    return 1;
  }
  assistente->bd_config->addr = strdup(addr);

  if(next_widget)
    gtk_widget_grab_focus(next_widget);

  return 0;
}

int assistente_get_server_user(GtkEntry *user_entry, gpointer next_widget){

  const gchar *user = gtk_entry_get_text(GTK_ENTRY(user_entry));
  if(!strlen(user)){
    return 1;
  }
  assistente->bd_config->user = strdup(user);
  if(next_widget)
    gtk_widget_grab_focus(next_widget);
  return 0;
}

int assistente_get_server_pass(GtkEntry *pass_entry, gpointer next_widget){

  const gchar *pass = gtk_entry_get_text(GTK_ENTRY(pass_entry));
  if(!strlen(pass)){
    return 1;
  }
  assistente->bd_config->pass = strdup(pass);
  if(next_widget)
    gtk_widget_grab_focus(next_widget);
  return 0;
}

GtkWidget *assistente_get_page(int page_num){

  switch (page_num) {
    case APRESENTACAO_PAGE:
      return pages_get_apresentacao_page();

    case BD_CONFIG_PAGE:
      return pages_get_bdconfig_page();

    case EMPRESA_CONFIG_PAGE:
      //page = gtk_box_new(1,0);
      //descr_label = gtk_label_new(apresentacao_txt);
      //gtk_box_pack_start(GTK_BOX(page), descr_label,0,0,5);
      //return page;
      return NULL;

    case CONCLUSAO_PAGE:
      return pages_get_conclusao_page();
  }

  return NULL;
}

int assistente_init(){

  if(!(assistente = assistente_render_wnd())){
    return 1;
  }
  assistente->bd_config = malloc(sizeof(struct _bd_config));

  return 0;
}

struct _assistente *assistente_render_wnd(){

  GtkWidget *wnd = gtk_assistant_new();
  struct _assistente *assistente = malloc(sizeof(struct _assistente));
  GtkWidget *apres = assistente_get_page(APRESENTACAO_PAGE);
  GtkWidget *bdconfig_page = assistente_get_page(BD_CONFIG_PAGE);
  GtkWidget *concl = assistente_get_page(CONCLUSAO_PAGE);

  assistente->wnd = wnd;

  assistente->init_page = apres;
  assistente->bdconfig_page = bdconfig_page;
  assistente->finish_page = concl;

  gtk_assistant_insert_page (GTK_ASSISTANT(assistente->wnd), assistente->init_page, APRESENTACAO_PAGE);
  gtk_assistant_insert_page (GTK_ASSISTANT(assistente->wnd), assistente->bdconfig_page, BD_CONFIG_PAGE);
  gtk_assistant_insert_page (GTK_ASSISTANT(assistente->wnd), assistente->finish_page, CONCLUSAO_PAGE);

  gtk_assistant_set_page_complete (GTK_ASSISTANT(assistente->wnd), assistente->init_page, TRUE);

  g_signal_connect(assistente->wnd, "cancel", G_CALLBACK(gtk_main_quit), NULL);
  gtk_widget_show_all(wnd);

  return assistente;
}
