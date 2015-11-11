#version 330 core

struct Material {
    sampler2D diffuse;
    vec3 cAmbient;
    vec3 cDiffuse;
    vec3 cSpecular;
    float shininess;
};

in vec3 fsPosition;
in vec3 fsNormal;
in vec2 fsTextureCoords;

uniform vec3 cameraPosition;
uniform Material material;

vec3 silhouette();

vec3 normal = normalize(fsNormal);
vec3 viewDirection = normalize(cameraPosition - fsPosition);
vec3 diffuseTexColor = vec3(texture(material.diffuse, fsTextureCoords))
                     + silhouette();

vec3 ambientComponent(vec3 lightColor) {
    return lightColor * material.cAmbient * diffuseTexColor;
}

vec3 diffuseComponent(vec3 lightColor, vec3 lightDirection) {
    float diffuseCoeff = dot(normal, lightDirection);
    if (diffuseCoeff > 0.2) { diffuseCoeff = 1.0; }
    else if (diffuseCoeff > 0.0) { diffuseCoeff = 0.3; }
    else { diffuseCoeff = 0.0; }
    
    return lightColor * material.cDiffuse * diffuseCoeff * diffuseTexColor;
}

vec3 specularComponent(vec3 lightColor, vec3 lightDirection) {
    vec3 reflectedDirection = reflect(-lightDirection, normal);
    
    float specularCoeff = pow(
        max(dot(viewDirection, reflectedDirection), 0.0),
        material.shininess
    );
    if (specularCoeff < 0.5) { specularCoeff = 0.0; }
    else { specularCoeff = 1.0; }
    
    return lightColor * material.cSpecular * specularCoeff;
}

/**
 * Computes the silhouette offset color. The computed color must be added
 * to the object's color (e.g. texture color) for the current fragment. The
 * silhouette is not completely black, it only darkens the current object's
 * color.
 */
vec3 silhouette() {
    float silhouetteCoeff = abs(dot(viewDirection, normal));
    
    if (silhouetteCoeff < 0.2) {
        return vec3(-0.2, -0.2, -0.2);
    }
    else {
        return vec3(0.0, 0.0, 0.0);
    }
}
