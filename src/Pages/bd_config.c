#include "bd_config.h"

GtkWidget *pages_get_bdconfig_page(){
  GtkWidget *page = gtk_box_new(1,0);
  char *db_config_txt = "Preencha as configurações do banco de dados";
  GtkWidget *descr_label;
  GtkWidget *bd_server_frame;
  GtkWidget *bd_server_entry;
  GtkWidget *bd_server_popover;

  GtkWidget *bd_user_frame;
  GtkWidget *bd_user_entry;
  GtkWidget *bd_user_popover;

  GtkWidget *bd_pass_frame;
  GtkWidget *bd_pass_entry;
  GtkWidget *bd_pass_popover;

  GtkWidget *bd_box;

  descr_label = gtk_label_new(db_config_txt);

  bd_server_entry = gtk_entry_new();
  bd_server_frame = gtk_frame_new("Endereço do Servidor");
  bd_server_popover = gtk_popover_new(bd_server_entry);

  gtk_container_add(GTK_CONTAINER(bd_server_frame), bd_server_entry);

  bd_user_entry = gtk_entry_new();
  bd_user_frame = gtk_frame_new("Usuário");
  bd_user_popover = gtk_popover_new(bd_user_entry);

  gtk_container_add(GTK_CONTAINER(bd_user_frame), bd_user_entry);

  bd_pass_entry = gtk_entry_new();
  bd_pass_frame = gtk_frame_new("Senha");
  bd_pass_popover = gtk_popover_new(bd_pass_entry);
  gtk_container_add(GTK_CONTAINER(bd_pass_frame), bd_pass_entry);

  g_signal_connect(bd_server_entry, "activate", G_CALLBACK(assistente_get_server_addr),bd_user_entry);
  g_signal_connect(bd_server_entry, "activate", G_CALLBACK(validate_dbpage),bd_server_popover);

  g_signal_connect(bd_user_entry, "activate", G_CALLBACK(assistente_get_server_user),bd_pass_entry);
  g_signal_connect(bd_user_entry, "activate", G_CALLBACK(validate_dbpage),bd_user_popover);

  g_signal_connect(bd_pass_entry, "activate", G_CALLBACK(assistente_get_server_pass),NULL);
  g_signal_connect(bd_pass_entry, "activate", G_CALLBACK(validate_dbpage),bd_pass_popover);

  bd_box = gtk_box_new(1,0);
  gtk_box_pack_start(GTK_BOX(bd_box), bd_server_frame,0,0,5);
  gtk_box_pack_start(GTK_BOX(bd_box), bd_user_frame,0,0,5);
  gtk_box_pack_start(GTK_BOX(bd_box), bd_pass_frame,0,0,5);

  gtk_box_pack_start(GTK_BOX(page), descr_label,0,0,5);
  gtk_box_pack_start(GTK_BOX(page), bd_box,0,0,5);
  return page;
}
