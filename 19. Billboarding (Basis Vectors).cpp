#include <iostream>
class RenderBillBoarding {

};
void cRenderingContext::RenderBillBoarding(size_t iTexture, float flRadius, Vector vecUp, Vector vecRight) {
    vecUp = vecUp * flRadius;
    vecRight = vecRight * flRadius;

    BindTexture (iTexture);

    BeginRenderTrifan();
        TexCoord(0.0f, 0.0f);
        Vertex(-vecUp-vecRight);

        TexCoord(1.0f, 0.0f);
        Vertex(-vecUp+vecRight);
        TexCoord(1.0f, 1.0f);
        Vertex(vecUp+vecRight);
        TexCoord(0.0f, 1.0f);
        Vertex(vecUp-vecRight);
    EndRender();
 }