#pragma once

#include "shaders/programs.hpp"

#include "drape/mesh_object.hpp"

#include "geometry/rect2d.hpp"

#include <string>

namespace dp
{
class GpuProgram;
}  // namespace dp

namespace gpu
{
class ProgramManager;
}  // namespace gpu

namespace df
{
class RendererContext
{
public:
  virtual ~RendererContext() = default;
  virtual gpu::Program GetGpuProgram() const = 0;
  virtual void PreRender(ref_ptr<gpu::ProgramManager> mng) {}
  virtual void PostRender() {}
protected:
  void BindTexture(uint32_t textureId, ref_ptr<dp::GpuProgram> prg,
                   std::string const & uniformName, uint8_t slotIndex,
                   uint32_t filteringMode, uint32_t wrappingMode);
};

class ScreenQuadRenderer: public dp::MeshObject
{
  using TBase = dp::MeshObject;
public:
  ScreenQuadRenderer();

  void SetTextureRect(m2::RectF const & rect);
  m2::RectF const & GetTextureRect() const { return m_textureRect; }

  void Render(ref_ptr<gpu::ProgramManager> mng, ref_ptr<RendererContext> context);
  void RenderTexture(ref_ptr<gpu::ProgramManager> mng, uint32_t textureId, float opacity);

private:
  void Rebuild();

  m2::RectF m_textureRect = m2::RectF(0.0f, 0.0f, 1.0f, 1.0f);

  drape_ptr<RendererContext> m_textureRendererContext;
};
}  // namespace df
