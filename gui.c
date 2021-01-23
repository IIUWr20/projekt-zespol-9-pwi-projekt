#include<gtk/gtk.h>

int a;
int b;

static void toggled_rodzaj(GtkWidget* widget,gpointer data){

}

static void toggled_typ(GtkWidget* widget,gpointer data){

}

static void value_changed_a(GtkWidget* widget,gpointer data){
    a = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(widget));
}

static void value_changed_b(GtkWidget* widget,gpointer data){
    b = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(widget));
}

static void rozpocznij(GtkWidget* widget,gpointer data){
    //const char *text = gtk_entry_get_text(GTK_ENTRY(data));
    g_print("%i",a);
    g_print("%i",b);
}

int main(int argc,char *argv[]){
    gtk_init(&argc, &argv);
    GtkWidget *window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window),"Program Szyfrujacy/Deszyfrujacy");
    gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
    gtk_container_set_border_width(GTK_CONTAINER(window), 30);
    g_signal_connect(G_OBJECT(window),"destroy",G_CALLBACK(gtk_main_quit),NULL);

    GtkAdjustment *adjustmenta = gtk_adjustment_new(0,0,10,1,2,0);
    GtkAdjustment *adjustmentb = gtk_adjustment_new(0,0,10,1,2,0);

    GtkWidget *okno = gtk_box_new(GTK_ORIENTATION_VERTICAL,5);

    GtkWidget *szyfr1 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,5);
    GtkWidget *szyfr2 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,5);
    GtkWidget *szyfr3 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,5);

    GtkWidget *vinegere = gtk_radio_button_new_with_label(NULL,"Szyfr Vinegere");
    GtkWidget *afiniczny = gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON(vinegere),"Szyfr Afiniczny");
    GtkWidget *rosnacy = gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON(vinegere),"Szyfr Rosnacy");

    g_signal_connect(vinegere,"toggled",G_CALLBACK(toggled_rodzaj),(gpointer)"1");
    g_signal_connect(afiniczny,"toggled",G_CALLBACK(toggled_rodzaj),(gpointer)"2");
    g_signal_connect(rosnacy,"toggled",G_CALLBACK(toggled_rodzaj),(gpointer)"3");

    GtkWidget *typ = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,5);

    GtkWidget *szyfrujacy = gtk_radio_button_new_with_label(NULL,"Zaszyfrowac");
    GtkWidget *deszyfrujacy = gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON(szyfrujacy),"Odszyfrowac");

    g_signal_connect(szyfrujacy,"toggled",G_CALLBACK(toggled_typ),(gpointer)"1");
    g_signal_connect(deszyfrujacy,"toggled",G_CALLBACK(toggled_typ),(gpointer)"2");

    GtkWidget *tekst = gtk_label_new("Wybierz preferowany szyfr i czy ma zasyfrowac czy odszyfrowac plik");

    GtkWidget *klucz = gtk_entry_new();

    GtkWidget *zmiennaa = gtk_spin_button_new(GTK_ADJUSTMENT(adjustmenta),0,0);
    GtkWidget *zmiennab = gtk_spin_button_new(GTK_ADJUSTMENT(adjustmentb),0,0);
    g_signal_connect(zmiennaa,"value-changed",G_CALLBACK(value_changed_a),NULL);
    g_signal_connect(zmiennab,"value-changed",G_CALLBACK(value_changed_b),NULL);

    GtkWidget *start = gtk_button_new_with_label("Rozpocznij Proces");
    g_signal_connect(G_OBJECT(start),"clicked",G_CALLBACK(rozpocznij),klucz);

    gtk_container_add(GTK_CONTAINER(window), okno);
    gtk_container_add(GTK_CONTAINER(okno),tekst);
    gtk_container_add(GTK_CONTAINER(okno),szyfr1);
    gtk_container_add(GTK_CONTAINER(okno),szyfr2);
    gtk_container_add(GTK_CONTAINER(okno),szyfr3);
    gtk_container_add(GTK_CONTAINER(okno),typ);
    gtk_container_add(GTK_CONTAINER(okno),start);

    gtk_box_pack_start(GTK_BOX(szyfr1),vinegere,FALSE,FALSE,0);
    gtk_box_pack_start(GTK_BOX(szyfr2),afiniczny,FALSE,FALSE,0);
    gtk_box_pack_start(GTK_BOX(szyfr3),rosnacy,FALSE,FALSE,0);

    gtk_box_pack_start(GTK_BOX(szyfr1),klucz,TRUE,FALSE,0);

    gtk_box_pack_start(GTK_BOX(szyfr2),zmiennaa,TRUE,FALSE,0);
    gtk_box_pack_start(GTK_BOX(szyfr2),zmiennab,TRUE,FALSE,0);

    gtk_box_pack_start(GTK_BOX(typ),szyfrujacy,TRUE,FALSE,0);
    gtk_box_pack_start(GTK_BOX(typ),deszyfrujacy,TRUE,FALSE,0);

    gtk_widget_show_all(window);
    gtk_main();
 return 0;
}
