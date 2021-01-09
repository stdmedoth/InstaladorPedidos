#include "conclusao.h"

GtkWidget *pages_get_conclusao_page(){
  GtkWidget *page = gtk_box_new(0,0);
  char *conclusao_txt = "Processo Finalizado";
  GtkWidget *descr_label = gtk_label_new(conclusao_txt);
  const gchar *css_data = ""
  "#conclusao_label "
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

  gtk_widget_set_name(descr_label, "conclusao_label");
  gtk_box_pack_start(GTK_BOX(page), descr_label,0,0,5);
  return page;
}
