#ifndef SHADER_H
#define SHADER_H

#include "Common.h"

#include <QObject>
#include <QOpenGLFunctions>
#include <QOpenGLShader>

class Shader : protected QOpenGLFunctions
{
public:
    Shader(ShaderType type);

    bool init();
    bool bind();
    void release();

    void addPath(QOpenGLShader::ShaderTypeBit type, const QString &path);
    void addUniform(const QString &uniform);
    void addUniforms(const QStringList &uniforms);
    void setUniformArray(const QString &uniform, int size);
    void addAttribute(const QString &attribute);
    void addAttributes(const QStringList &attributes);

    void setUniformValue(const QString &name, int value);
    void setUniformValue(const QString &name, unsigned int value);
    void setUniformValue(const QString &name, float value);
    void setUniformValue(const QString &name, const QVector3D &value);
    void setUniformValue(const QString &name, const QVector4D &value);
    void setUniformValue(const QString &name, const QMatrix4x4 &value);
    void setUniformValue(const QString &name, const QMatrix3x3 &value);
    void setUniformValueArray(const QString &name, const QVector<QVector3D> &values);
    void setSampler(const QString &name, unsigned int unit, unsigned int id, GLenum target = GL_TEXTURE_2D);

    ShaderType type() const;

private:
    QString getShaderTypeString(QOpenGLShader::ShaderTypeBit type);

private:
    QOpenGLShaderProgram *mProgram;
    QMap<QOpenGLShader::ShaderTypeBit, QString> mPaths;
    QMap<QString, GLuint> mLocations;

    ShaderType mType;
    QString mShaderName;

    QStringList mAttributes;
    QStringList mUniforms;
    QMap<QString, int> mUniformArrays;
};
#endif // SHADER_H
