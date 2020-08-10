#include "client.h"



void mx_set_styles(t_s *s) {
    if (!strcmp(s->h->theme, "black")) {
        mx_set_black(s);
        mx_set_standart_style(s);
        return;
    }
    if (!strcmp(s->h->theme, "white")) {
        mx_set_white(s);
        mx_set_standart_style(s);
        return;
    }
    mx_set_black(s);
}

void mx_4_chat_init(t_s *s) {
    s->h->c_v_window = gtk_widget_get_style_context(s->h->v_window);
    s->h->c_v_l_btn_ru = gtk_widget_get_style_context(s->h->v_l_btn_ru);
    s->h->c_v_l_btn_en = gtk_widget_get_style_context(s->h->v_l_btn_en);
    s->h->c_v_l_btn_en = gtk_widget_get_style_context(s->h->v_l_btn_en);
    s->h->c_v_l_btn_rm = gtk_widget_get_style_context(s->h->v_l_btn_rm);
    s->h->c_v_t_btn_b = gtk_widget_get_style_context(s->h->v_t_btn_b);
    s->h->c_v_t_btn_w = gtk_widget_get_style_context(s->h->v_t_btn_w);
    s->h->c_v_scroll = gtk_widget_get_style_context(s->h->v_scroll);
    s->h->c_v_main_e = gtk_widget_get_style_context(s->h->v_main_e);
    s->h->c_v_bt_e = gtk_widget_get_style_context(s->h->v_bt_e);
    mx_set_styles(s);
}


void mx_set_b(GtkWidget *widget, t_s *s) {
    (void)widget;
    mx_set_black(s);
    s->h->theme = "black";
}

void mx_set_w(GtkWidget *widget, t_s *s) {
    (void)widget;
    mx_set_white(s);
    s->h->theme = "white";
}

void mx_set_engl(t_s *s) {
    gtk_button_set_label((GtkButton *)s->h->v_l_btn_ru, "RUS");
    gtk_button_set_label((GtkButton *)s->h->v_l_btn_en, "ENG");
    gtk_button_set_label((GtkButton *)s->h->v_l_btn_rm, "Delete");
    gtk_button_set_label((GtkButton *)s->h->v_bt_e, "Send");
    gtk_button_set_label((GtkButton *)s->h->v_bt_inf, "Info");
    s->h->lang = "eng";
}

