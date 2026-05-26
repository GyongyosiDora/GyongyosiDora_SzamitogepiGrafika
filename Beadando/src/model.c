#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GL/gl.h>

#include "model.h"

#define MAX_VERTICES 10000
#define MAX_LINE_LENGTH 256

static void add_vertex(Model* model, Vertex v, float u, float tex_v) {
    Vertex* new_vertices = realloc(model->vertices, (model->vertex_count + 1) * sizeof(Vertex));

    if (new_vertices == NULL) {
        return;
    }

    v.u = u;
    v.v = tex_v;

    model->vertices = new_vertices;
    model->vertices[model->vertex_count] = v;
    model->vertex_count++;
}

int load_model(Model* model, const char* filename) {
    FILE* file = fopen(filename, "r");
    char line[MAX_LINE_LENGTH];

    Vertex temp_vertices[MAX_VERTICES];
    int temp_vertex_count = 0;

    float temp_u[MAX_VERTICES];
    float temp_v[MAX_VERTICES];
    int temp_uv_count = 0;

    model->vertices = NULL;
    model->vertex_count = 0;

    if (file == NULL) {
        fprintf(stderr, "Cannot open model: %s\n", filename);
        return 0;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        if (strncmp(line, "v ", 2) == 0) {
            sscanf(
                line,
                "v %f %f %f",
                &temp_vertices[temp_vertex_count].x,
                &temp_vertices[temp_vertex_count].y,
                &temp_vertices[temp_vertex_count].z
            );

            temp_vertex_count++;
        }

        if (strncmp(line, "vt ", 3) == 0) {
            sscanf(line, "vt %f %f", &temp_u[temp_uv_count], &temp_v[temp_uv_count]);
            temp_uv_count++;
        }

        if (strncmp(line, "f ", 2) == 0) {
            int a, b, c, ta, tb, tc, na, nb, nc;

            if (sscanf(line, "f %d/%d/%d %d/%d/%d %d/%d/%d", &a, &ta, &na, &b, &tb, &nb, &c, &tc, &nc) == 9) {
                add_vertex(model, temp_vertices[a-1], temp_u[ta-1], temp_v[ta-1]);
                add_vertex(model, temp_vertices[b-1], temp_u[tb-1], temp_v[tb-1]);
                add_vertex(model, temp_vertices[c-1], temp_u[tc-1], temp_v[tc-1]);
            } else if (sscanf(line, "f %d %d %d", &a, &b, &c) == 3) {
                add_vertex(model, temp_vertices[a-1], 0.0f, 0.0f);
                add_vertex(model, temp_vertices[b-1], 0.0f, 0.0f);
                add_vertex(model, temp_vertices[c-1], 0.0f, 0.0f);
            }
        }
    }

    fclose(file);

    return 1;
}

void draw_model(const Model* model) {
    int i;

    glBegin(GL_TRIANGLES);

    for (i = 0; i < model->vertex_count; i++) {
        glTexCoord2f(model->vertices[i].u, model->vertices[i].v);
        glVertex3f(model->vertices[i].x, model->vertices[i].y, model->vertices[i].z);
    }

    glEnd();
}

void destroy_model(Model* model)
{
    free(model->vertices);

    model->vertices = NULL;
    model->vertex_count = 0;
}

int load_model_named(Model* model, const char* filename, const char* object_name) {
    FILE* file = fopen(filename, "r");
    char line[MAX_LINE_LENGTH];
    Vertex temp_vertices[MAX_VERTICES];
    int temp_vertex_count = 0;
    float temp_u[MAX_VERTICES];
    float temp_v[MAX_VERTICES];
    int temp_uv_count = 0;
    int in_section = 0;

    model->vertices = NULL;
    model->vertex_count = 0;

    if (file == NULL) {
        fprintf(stderr, "Cannot open model: %s\n", filename);
        return 0;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        if (strncmp(line, "o ", 2) == 0) {
            char name[128];
            sscanf(line, "o %127s", name);
            in_section = (strcmp(name, object_name) == 0);
            continue;
        }

        if (strncmp(line, "v ", 2) == 0) {
            sscanf(line, "v %f %f %f",
                &temp_vertices[temp_vertex_count].x,
                &temp_vertices[temp_vertex_count].y,
                &temp_vertices[temp_vertex_count].z);
            temp_vertex_count++;
        }

        if (strncmp(line, "vt ", 3) == 0) {
            sscanf(line, "vt %f %f", &temp_u[temp_uv_count], &temp_v[temp_uv_count]);
            temp_uv_count++;
        }

        if (in_section && strncmp(line, "f ", 2) == 0) {
            int a, b, c, ta, tb, tc, na, nb, nc;
            if (sscanf(line, "f %d/%d/%d %d/%d/%d %d/%d/%d", &a, &ta, &na, &b, &tb, &nb, &c, &tc, &nc) == 9) {
                add_vertex(model, temp_vertices[a-1], temp_u[ta-1], temp_v[ta-1]);
                add_vertex(model, temp_vertices[b-1], temp_u[tb-1], temp_v[tb-1]);
                add_vertex(model, temp_vertices[c-1], temp_u[tc-1], temp_v[tc-1]);
            } else if (sscanf(line, "f %d %d %d", &a, &b, &c) == 3) {
                add_vertex(model, temp_vertices[a-1], 0.0f, 0.0f);
                add_vertex(model, temp_vertices[b-1], 0.0f, 0.0f);
                add_vertex(model, temp_vertices[c-1], 0.0f, 0.0f);
            }
        }
    }

    fclose(file);
    return 1;
}