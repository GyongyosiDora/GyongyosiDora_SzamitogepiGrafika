#ifndef MODEL_H
#define MODEL_H

typedef struct Vertex {
    float x;
    float y;
    float z;
    float u;
    float v;
} Vertex;

typedef struct Model {
    Vertex* vertices;
    int vertex_count;
} Model;

int load_model(Model* model, const char* filename);
void draw_model(const Model* model);
void destroy_model(Model* model);
int load_model_named(Model* model, const char* filename, const char* object_name);

#endif