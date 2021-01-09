#include "apresentacao.h"

GtkWidget *pages_get_apresentacao_page(){
  char *apresentacao_txt = "Olá! Vamos configurar o seu sistema?";
  char *nome_txt = "Pedidos";
  GtkWidget *nome_label;
  GtkWidget *descr_label;
  GtkWidget *page = gtk_box_new(0,0);
  const gchar *css_data = ""
  "#nome_label"
  "{color: Orange;\n"
  "font-size: 30px;\n"
  "}\n\n"
  "#apresentacao_label "
  "{color: Black;\n"
  "font-size: 30px;\n"
  "}\n\n";

  GError *error=NULL;
  GdkScreen *screen;
  GtkCssProvider *css_provider;
  screen = gdk_screen_get_default();
  css_provider = gtk_css_provider_new();


  gtk_style_context_add_provider_for_screen(screen,GTK_STYLE_PROVIDER(css_provider),GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
  if(!gtk_css_provider_load_from_data (css_provider, css_data, strlen(css_data), &error)){
    return NULL;
  }

  nome_label = gtk_label_new(nome_txt);
  descr_label = gtk_label_new(apresentacao_txt);
  gtk_widget_set_name(nome_label, "nome_label");
  gtk_widget_set_name(descr_label, "apresentacao_label");
  gtk_box_pack_start(GTK_BOX(page), nome_label,0,0,5);
  gtk_box_pack_start(GTK_BOX(page), descr_label,0,0,5);
  return page;
}
