#include <gtk/gtk.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

GtkWidget*d;void w(const gchar*p){int f=open(p,O_WRONLY);char*z=calloc(1,512);ssize_t W,T=0;do{T+=W=write(f,z,512);}while(W==512);close(f);free(z);}void o(GtkFileChooserButton*b,gpointer _){gchar*p=gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(b));w(p);g_free(p);}void s(){GtkWidget*b;d=gtk_dialog_new_with_buttons("Select Drive",0,GTK_DIALOG_MODAL,"_OK",GTK_RESPONSE_ACCEPT,0);b=gtk_file_chooser_button_new("Select Drive",GTK_FILE_CHOOSER_ACTION_OPEN);gtk_container_add(GTK_CONTAINER(GTK_DIALOG(d)->vbox),b);g_signal_connect(b,"file-set",G_CALLBACK(o),0);gtk_widget_show_all(d);}int main(int argc,char*argv[]){gtk_init(&argc,&argv);s();gtk_dialog_run(GTK_DIALOG(d));return 0;}
