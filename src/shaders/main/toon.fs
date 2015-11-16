#version 330 core

struct Material {
    sampler2D diffuseMap;
    sampler2D normalMap;
    bool normalMapIsSet;
    
    vec4 cAmbient;
    vec4 cDiffuse;
    vec4 cSpecular;
    float shininess;
};

in vec3 fsPosition;
in vec3 fsNormal;
in vec2 fsTextureCoords;

uniform vec3 cameraPosition;
uniform Material material;
uniform bool setSilhouette;

vec3 viewDirection = normalize(cameraPosition - fsPosition);

vec3 getNormal() {
    if (!material.normalMapIsSet) { return normalize(fsNormal); }
    
    // retrieve normal information in the texture color (range [0,1])
    vec3 normal = texture(material.normalMap, fsTextureCoords).rgb;
    
    // return normal in range [-1, 1]
    return normalize(normal * 2.0 - 1.0);
}

/**
 * Computes the silhouette offset color. The computed color must be added
 * to the object's color (e.g. texture color) for the current fragment. The
 * silhouette is not completely black, it only darkens the current object's
 * color.
 */
vec4 silhouette() {
    if (!setSilhouette) { return vec4(0.0, 0.0, 0.0, 0.0); }
    
    float silhouetteCoeff = abs(dot(viewDirection, getNormal()));
    
    if (silhouetteCoeff < 0.2) {
        return vec4(-0.2, -0.2, -0.2, 0.0);
    }
    else {
        return vec4(0.0, 0.0, 0.0, 0.0);
    }
}

vec4 diffuseTexColor() {
    vec4 diffuseTexColor = texture(material.diffuseMap, fsTextureCoords);
    if (diffuseTexColor.a < 0.1) { discard; } // alpha testing
    
    return diffuseTexColor + silhouette();
}

vec4 ambientComponent(vec4 lightColor) {
    return lightColor * material.cAmbient * diffuseTexColor();
}

vec4 diffuseComponent(vec4 lightColor, vec3 lightDirection) {
    float diffuseCoeff = dot(getNormal(), lightDirection);
    if (diffuseCoeff > 0.2) { diffuseCoeff = 1.0; }
    else if (diffuseCoeff > 0.0) { diffuseCoeff = 0.3; }
    else { diffuseCoeff = 0.2; }
    
    return lightColor * material.cDiffuse * diffuseCoeff * diffuseTexColor();
}

vec4 specularComponent(vec4 lightColor, vec3 lightDirection) {
    vec3 reflectedDirection = reflect(-lightDirection, getNormal());
    
    float specularCoeff = pow(
        max(dot(viewDirection, reflectedDirection), 0.0),
        material.shininess
    );
    if (specularCoeff < 0.5) { specularCoeff = 0.0; }
    else { specularCoeff = 1.0; }
    
    return lightColor * material.cSpecular * specularCoeff;
}
