//
//  EdgeTangentFilter.cpp
//  ArtNouveau
//
//  Created by Matthew Fargo on 2014/07/22.
//
//

#include "EdgeTangentFilter.h"

EdgeTangentFilter::EdgeTangentFilter(float width, float height) : Abstract3x3TextureSamplingFilter(width, height, ofVec2f(1, 1)) {
    _setupShader();
}
EdgeTangentFilter::~EdgeTangentFilter() {}


string EdgeTangentFilter::_getFragSrc() {
    return GLSL_STRING(120,
                       uniform sampler2D inputImageTexture;
                       
                       varying vec2 textureCoordinate;
                       varying vec2 leftTextureCoordinate;
                       varying vec2 rightTextureCoordinate;
                       
                       varying vec2 topTextureCoordinate;
                       varying vec2 topLeftTextureCoordinate;
                       varying vec2 topRightTextureCoordinate;
                       
                       varying vec2 bottomTextureCoordinate;
                       varying vec2 bottomLeftTextureCoordinate;
                       varying vec2 bottomRightTextureCoordinate;
                       
                       const float MAX_VAL = 1020.0;

                       void main() {
                           float bottomColor = texture2D(inputImageTexture, bottomTextureCoordinate).r;
                           float bottomLeftColor = texture2D(inputImageTexture, bottomLeftTextureCoordinate).r;
                           float bottomRightColor = texture2D(inputImageTexture, bottomRightTextureCoordinate).r;
                           vec4 centerColor = texture2D(inputImageTexture, textureCoordinate);
                           float leftColor = texture2D(inputImageTexture, leftTextureCoordinate).r;
                           float rightColor = texture2D(inputImageTexture, rightTextureCoordinate).r;
                           float topColor = texture2D(inputImageTexture, topTextureCoordinate).r;
                           float topRightColor = texture2D(inputImageTexture, topRightTextureCoordinate).r;
                           float topLeftColor = texture2D(inputImageTexture, topLeftTextureCoordinate).r;
                           
                           centerColor.r = (topRightColor + 2*rightColor + bottomRightColor - topLeftColor - 2*leftColor - bottomLeftColor)/MAX_VAL;
                           centerColor.g = (bottomLeftColor + 2*bottomColor + bottomRightColor - topLeftColor - 2*topColor - topRightColor)/MAX_VAL;
                           
                           vec4 v = vec4(-centerColor.g, centerColor.r, 0, centerColor.a);
                           v.b = length(v.xy);
                           
                           if (v.b != 0.0) {
                               v.r /= v.b;
                               v.g /= v.b;
                           }
                           
                           v.b /= (1.0/320.0);
                           gl_FragColor = v;
                       }
                       );
}
