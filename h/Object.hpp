class Object
{
    protected:
        float pos[3];
        float posOffset[3];
        float anchor[3];
        float rot[3];
        float scale[3];

        bool calculateOffset;
        bool calculateSize;
        bool calculateVertices;

        void CalculateOffset();

    public:
        void SetRotation(float _x, float _y, float _z);
        void Rotate(float _x, float _y, float _z);
};

class Cube : public Object
{
    private:
        float sizeBase[3];
        float sizeHalf[3];
        float col[8][3];
        float vert[8][3];
        const float norm[8][3] =
        {
            { -1.0f, -1.0f, -1.0f },
            { -1.0f, -1.0f,  1.0f },
            { -1.0f,  1.0f, -1.0f },
            { -1.0f,  1.0f,  1.0f },
            {  1.0f, -1.0f, -1.0f },
            {  1.0f, -1.0f,  1.0f },
            {  1.0f,  1.0f, -1.0f },
            {  1.0f,  1.0f,  1.0f }
        };
        
        void CalculateSize();
        void CalculateVertices();

        void DrawFace(int _face);
        void DrawVertex(int _vertex);

    public:
        Cube(float _x, float _y, float _z, float _w, float _h, float _d);
        void SetPosition(float _x, float _y, float _z);
        void Move(float _x, float _y, float _z);
        void SetAnchor(float _x, float _y, float _z);
        void MoveAnchor(float _x, float _y, float _z);
        void SetColor(int _vertex, float _r, float _g, float _b);
        void SetColor(float _r, float _g, float _b);
        void SetSize(float _w, float _h, float _d);
        void SetScale(float _x, float _y, float _z);
        void SetScale(float _scale);
        void Scale(float _scale);
        void Draw();
};

#define FACE_LEFT 0
#define FACE_RIGHT 1
#define FACE_BOTTOM 2
#define FACE_TOP 3
#define FACE_BACK 4
#define FACE_FRONT 5

#define VERTEX_LEFT_BOTTOM_BACK 0
#define VERTEX_LEFT_BOTTOM_FRONT 1
#define VERTEX_LEFT_TOP_BACK 2
#define VERTEX_LEFT_TOP_FRONT 3
#define VERTEX_RIGHT_BOTTOM_BACK 4
#define VERTEX_RIGHT_BOTTOM_FRONT 5
#define VERTEX_RIGHT_TOP_BACK 6
#define VERTEX_RIGHT_TOP_FRONT 7