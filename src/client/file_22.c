#include "client.h"



void mx_1_chat_init(t_s *s) {
    s->h->login = s->l->login;
    s->h->lang = s->l->lang;
    s->h->v_n = 0;
    s->h->theme = s->l->theme;
    mx_create_content(s);
    s->h->v_scroll = gtk_scrolled_window_new(0,0);
    s->h->vbox = gtk_box_new(TRUE, 0);
    s->h->T_b = gtk_box_new(FALSE, 0);
    s->h->scr_box = gtk_box_new(FALSE, 0);
    s->h->ent_box = gtk_box_new(FALSE, 0);
    s->h->btns_b = gtk_box_new(FALSE, 0);
    s->h->v_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    s->h->cssProv = gtk_css_provider_new();
    s->h->v_listbox = gtk_list_box_new();
    s->h->v_main_e = gtk_entry_new();
    g_signal_connect(G_OBJECT(s->h->v_bt_e), 
    "clicked", G_CALLBACK(mx_do_s), s);
}


void mx_2_chat_init(t_s *s) {
    gtk_box_pack_start(GTK_BOX(s->h->T_b), s->h->v_l_btn_ru, FALSE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(s->h->T_b), s->h->v_l_btn_en, FALSE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(s->h->T_b), s->h->v_l_btn_rm, FALSE, TRUE, 0);
    gtk_widget_set_size_request(s->h->v_l_btn_rm, 200, 50);
    gtk_box_pack_start(GTK_BOX(s->h->vbox), s->h->T_b, FALSE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(s->h->vbox), s->h->scr_box, FALSE, TRUE, 0);
    gtk_container_add(GTK_CONTAINER(s->h->v_window), s->h->vbox);
    gtk_window_set_resizable((GtkWindow *)s->h->v_window, FALSE);
    gtk_box_pack_start(GTK_BOX(s->h->scr_box), s->h->v_scroll, TRUE, TRUE, 0);
    gtk_widget_set_size_request(s->h->v_scroll, 1800, 950);
    gtk_box_pack_start(GTK_BOX(s->h->ent_box), s->h->v_main_e, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(s->h->ent_box), s->h->v_bt_e, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(s->h->vbox), s->h->ent_box, TRUE, FALSE, 0);
    gtk_widget_set_size_request(s->h->v_bt_e, 200, 50);
}

void mx_remove_class_black(t_s *s) {
    gtk_style_context_remove_class(s->h->c_v_l_btn_ru, "black");
    gtk_style_context_remove_class(s->h->c_v_l_btn_en, "black");
    gtk_style_context_remove_class(s->h->c_v_l_btn_rm, "black");
    gtk_style_context_remove_class(s->h->c_v_scroll, "black");
    gtk_style_context_remove_class(s->h->c_v_main_e, "black");
    gtk_style_context_remove_class(s->h->c_v_bt_e, "black");
}

void mx_remove_class_white(t_s *s) {
    gtk_style_context_remove_class(s->h->c_v_l_btn_ru, "white");
    gtk_style_context_remove_class(s->h->c_v_l_btn_en, "white");
    gtk_style_context_remove_class(s->h->c_v_l_btn_rm, "white");
    gtk_style_context_remove_class(s->h->c_v_scroll, "white");
    gtk_style_context_remove_class(s->h->c_v_main_e, "white");
    gtk_style_context_remove_class(s->h->c_v_bt_e, "white");
}

