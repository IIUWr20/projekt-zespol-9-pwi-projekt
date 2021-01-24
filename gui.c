#include<gtk/gtk.h>
#include "func.h"

int a;
int b;
char *plik;
int wybor[2] = {1,1};
GtkWidget *window = NULL;

static void toggled_rodzaj(GtkWidget* widget,gpointer data){
    if(strcmp((char*)data,"1")==0){
        if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget)))
            wybor[0]=1;
    }
    else if(strcmp((char*)data,"2")==0){
        if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget)))
            wybor[0]=2;
    }
    else if(strcmp((char*)data,"3")==0){
        if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget)))
            wybor[0]=3;
    }
}

static void toggled_typ(GtkWidget* widget,gpointer data){
    if(strcmp((char*)data,"1")==0){
        if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget)))
            wybor[1]=1;
    }
    else if(strcmp((char*)data,"2")==0){
        if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget)))
            wybor[1]=2;
    }
}

static void value_changed_a(GtkWidget* widget,gpointer data){
    a = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(widget));
}

static void value_changed_b(GtkWidget* widget,gpointer data){
    b = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(widget));
}

static void open_dialog(GtkWidget* button, gpointer data){
    GtkWidget *dialog = gtk_file_chooser_dialog_new("Wybierz plik", GTK_WINDOW(window),GTK_FILE_CHOOSER_ACTION_OPEN,"Wybierz",GTK_RESPONSE_ACCEPT,"Anuluj",GTK_RESPONSE_REJECT,NULL);
    gtk_widget_show_all(dialog);
    gint resp=gtk_dialog_run(GTK_DIALOG(dialog));
    if(resp==GTK_RESPONSE_ACCEPT) {
        plik = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
        gtk_button_set_label(GTK_BUTTON(button), plik);
    }
    gtk_widget_destroy(dialog);
}

static char* save_dialog(){
    GtkWidget *dialog = gtk_file_chooser_dialog_new("Zapisz do...", GTK_WINDOW(window),GTK_FILE_CHOOSER_ACTION_SAVE,"Wybierz",GTK_RESPONSE_ACCEPT,"Anuluj",GTK_RESPONSE_REJECT,NULL);
    gtk_file_chooser_set_current_name(GTK_FILE_CHOOSER(dialog), "wynik.txt");
    gtk_widget_show_all(dialog);
    gint resp=gtk_dialog_run(GTK_DIALOG(dialog));
    char* plik_out = NULL;
    if(resp==GTK_RESPONSE_ACCEPT)
        plik_out = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
    gtk_widget_destroy(dialog);

    return plik_out;
}

static void rozpocznij(GtkWidget* widget, gpointer data){
    char* plik_out = save_dialog();

    if (plik_out == NULL)
        return;

    if(wybor[0]==1){
        const char *text = gtk_entry_get_text(GTK_ENTRY(data));
        if(wybor[1]==1){
            vigenereEncipher((char*)text,plik,plik_out);
        }
        else if(wybor[1]==2){
            vigenere_decipher((char*)text,plik,plik_out);
        }
    }
    else if(wybor[0]==2){
        if(wybor[1]==1){
            szyfr_afiniczny(plik,plik_out,a,b);
        }
        else if(wybor[1]==2){
            decipher(plik,plik_out,a,b);
        }
    }
    else if(wybor[0]==3){
        if(wybor[1]==1){
            szyfr_rosnacy(plik,plik_out);
        }
        else if(wybor[1]==2){
            de_szyfr_rosnacy(plik,plik_out);
        }
    }
}

int main(int argc,char *argv[]){
    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
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

    GtkWidget *vinegere = gtk_radio_button_new_with_label(NULL,"Szyfr Vigenere");
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

    GtkWidget *tekst = gtk_label_new("Wybierz preferowany szyfr i czy ma zaszyfrowac czy odszyfrowac plik");

    GtkWidget *klucz = gtk_entry_new();
    GtkWidget *klucz_opis = gtk_label_new("klucz:");

    GtkWidget *zmiennaa = gtk_spin_button_new(GTK_ADJUSTMENT(adjustmenta),0,0);
    GtkWidget *zmiennab = gtk_spin_button_new(GTK_ADJUSTMENT(adjustmentb),0,0);

    GtkWidget* zmiennaa_opis = gtk_label_new("a:");
    GtkWidget* zmiennab_opis = gtk_label_new("b:");

    g_signal_connect(zmiennaa,"value-changed",G_CALLBACK(value_changed_a),NULL);
    g_signal_connect(zmiennab,"value-changed",G_CALLBACK(value_changed_b),NULL);

    GtkWidget *start = gtk_button_new_with_label("Rozpocznij Proces");
    g_signal_connect(G_OBJECT(start),"clicked",G_CALLBACK(rozpocznij), klucz);

    GtkWidget *wplik = gtk_button_new_with_label("Wybierz plik");
    g_signal_connect(G_OBJECT(wplik),"clicked",G_CALLBACK(open_dialog), NULL);

    gtk_container_add(GTK_CONTAINER(window), okno);
    gtk_container_add(GTK_CONTAINER(okno),tekst);
    gtk_container_add(GTK_CONTAINER(okno),wplik);
    gtk_container_add(GTK_CONTAINER(okno),szyfr1);
    gtk_container_add(GTK_CONTAINER(okno),szyfr2);
    gtk_container_add(GTK_CONTAINER(okno),szyfr3);
    gtk_container_add(GTK_CONTAINER(okno),typ);
    gtk_container_add(GTK_CONTAINER(okno),start);

    gtk_box_pack_start(GTK_BOX(szyfr1),vinegere,FALSE,FALSE,0);
    gtk_box_pack_start(GTK_BOX(szyfr2),afiniczny,FALSE,FALSE,0);
    gtk_box_pack_start(GTK_BOX(szyfr3),rosnacy,FALSE,FALSE,0);

    GtkWidget *szyfr1_parametry = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,5);

    gtk_box_pack_start(GTK_BOX(szyfr1_parametry),klucz_opis,FALSE,FALSE,0);
    gtk_box_pack_start(GTK_BOX(szyfr1_parametry),klucz,FALSE,FALSE,0);
    gtk_box_pack_start(GTK_BOX(szyfr1),szyfr1_parametry,TRUE,FALSE,0);

    GtkWidget *szyfr2_zmiennaa = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,5);
    GtkWidget *szyfr2_zmiennab = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,5);

    gtk_box_pack_start(GTK_BOX(szyfr2_zmiennaa),zmiennaa_opis,FALSE,FALSE,0);
    gtk_box_pack_start(GTK_BOX(szyfr2_zmiennaa),zmiennaa,FALSE,FALSE,0);
    gtk_box_pack_start(GTK_BOX(szyfr2_zmiennab),zmiennab_opis,FALSE,FALSE,0);
    gtk_box_pack_start(GTK_BOX(szyfr2_zmiennab),zmiennab,FALSE,FALSE,0);

    gtk_box_pack_start(GTK_BOX(szyfr2),szyfr2_zmiennaa,TRUE,FALSE,0);
    gtk_box_pack_start(GTK_BOX(szyfr2),szyfr2_zmiennab,TRUE,FALSE,0);


    gtk_box_pack_start(GTK_BOX(typ),szyfrujacy,TRUE,FALSE,0);
    gtk_box_pack_start(GTK_BOX(typ),deszyfrujacy,TRUE,FALSE,0);

    gtk_widget_show_all(window);
    gtk_main();
 return 0;
}
