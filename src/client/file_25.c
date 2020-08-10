#include "client.h"



void mx_set_russ(t_s *s) {
    gtk_button_set_label((GtkButton *)s->h->v_l_btn_ru, "РУС");
    gtk_button_set_label((GtkButton *)s->h->v_l_btn_en, "АНГ");
    gtk_button_set_label((GtkButton *)s->h->v_l_btn_rm, "Удалить");
    gtk_button_set_label((GtkButton *)s->h->v_bt_e, "Отправить");
    gtk_button_set_label((GtkButton *)s->h->v_bt_inf, "Информация");
    s->h->lang = "rus";
}

void mx_set_en(GtkWidget *widget, t_s *s) {
    (void)widget;
    mx_set_engl(s);
    cJSON *send = cJSON_CreateObject();

    cJSON_AddStringToObject(send, "kind", "ui");
    cJSON_AddStringToObject(send, "login", s->h->login);
    cJSON_AddStringToObject(send, "tema", s->h->theme);
    cJSON_AddStringToObject(send, "lang", "eng");
    char *res = cJSON_Print(send);

    tls_write(s->c->tls, res, strlen(res) + 1);
}

void mx_set_ru(GtkWidget *widget, t_s *s) {
    (void)widget;
    mx_set_russ(s);
    cJSON *send = cJSON_CreateObject();

    cJSON_AddStringToObject(send, "kind", "ui");
    cJSON_AddStringToObject(send, "login", s->h->login);
    cJSON_AddStringToObject(send, "tema", s->h->theme);
    cJSON_AddStringToObject(send, "lang", "rus");
    char *res = cJSON_Print(send);

    tls_write(s->c->tls, res, strlen(res) + 1);
}

void mx_5_chat_init(t_s *s) {
    s->h->d_id = -2;
    s->h->is_output_matyki = 0;
    s->h->is_output_sound = 1;
    s->h->is_output_visual = 0;
    s->h->is_drop_all_messages = 0;
    g_signal_connect(G_OBJECT(s->h->v_l_btn_en), "clicked", 
        G_CALLBACK(mx_set_en), s);
    g_signal_connect(G_OBJECT(s->h->v_l_btn_ru), "clicked",
        G_CALLBACK(mx_set_ru), s);
    g_signal_connect(G_OBJECT(s->h->v_l_btn_rm), "clicked", 
        G_CALLBACK(mx_drop_acc), s);
    g_signal_connect(G_OBJECT(s->h->v_bt_inf), "clicked", 
        G_CALLBACK(mx_inf), s);
}


