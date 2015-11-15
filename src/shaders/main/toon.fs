#version 330 core

struct Material {
    sampler2D diffuse;
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

vec3 normal = normalize(fsNormal);
vec3 viewDirection = normalize(cameraPosition - fsPosition);

/**
 * Computes the silhouette offset color. The computed color must be added
 * to the object's color (e.g. texture color) for the current fragment. The
 * silhouette is not completely black, it only darkens the current object's
 * color.
 */
vec4 silhouette() {
    if (!setSilhouette) { return vec4(0.0, 0.0, 0.0, 0.0); }
    
    float silhouetteCoeff = abs(dot(viewDirection, normal));
    
    if (silhouetteCoeff < 0.2) {
        return vec4(-0.2, -0.2, -0.2, 0.0);
    }
    else {
        return vec4(0.0, 0.0, 0.0, 0.0);
    }
}

vec4 diffuseTexColor() {
    vec4 diffuseTexColor = texture(material.diffuse, fsTextureCoords);
    if (diffuseTexColor.a < 0.1) { discard; } // alpha testing
    
    return diffuseTexColor + silhouette();
}

vec4 ambientComponent(vec4 lightColor) {
    return lightColor * material.cAmbient * diffuseTexColor();
}

vec4 diffuseComponent(vec4 lightColor, vec3 lightDirection) {
    float diffuseCoeff = dot(normal, lightDirection);
    if (diffuseCoeff > 0.2) { diffuseCoeff = 1.0; }
    else if (diffuseCoeff > 0.0) { diffuseCoeff = 0.3; }
    else { diffuseCoeff = 0.2; }
    
    return lightColor * material.cDiffuse * diffuseCoeff * diffuseTexColor();
}

vec4 specularComponent(vec4 lightColor, vec3 lightDirection) {
    vec3 reflectedDirection = reflect(-lightDirection, normal);
    
    float specularCoeff = pow(
        max(dot(viewDirection, reflectedDirection), 0.0),
        material.shininess
    );
    if (specularCoeff < 0.5) { specularCoeff = 0.0; }
    else { specularCoeff = 1.0; }
    
    return lightColor * material.cSpecular * specularCoeff;
}
