#include "uls.h"

void mx_clear_filesattr(t_file *file, t_cmd *c);

void mx_clear_filesattr_list(t_list **fl, t_cmd *c) {
    t_list *q = *fl;
    t_list *tmp = NULL;

    if (!(*fl) || !fl)
        return;
    while (q) {
        mx_clear_filesattr(q->data, c);
        tmp = q->next;
        free(q);
        q = tmp;
    }
    *fl = NULL;
}

void mx_clear_filesattr(t_file *file, t_cmd *c) {
    if (!file)
        return;
    mx_strdel(&file->path);
    mx_strdel(&file->filename);
    if (c->print_func == long_format) {
        mx_strdel(&file->perm);
        mx_strdel(&file->owner);
        mx_strdel(&file->group);
    }
    else if (c->format_g)
        mx_strdel(&file->perm);
    free(file);
    file = NULL;
}
