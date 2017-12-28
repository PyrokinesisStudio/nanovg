#ifndef NANOVG_NULL_H
#define NANOVG_NULL_H

NVGcontext* nvgCreateNull();
void nvgDeleteNull(NVGcontext* ctx);

#ifdef NANOVG_NULL_IMPLEMENTATION
#include "nanovg.h"

struct GLNVGcontext
{};

static int glnvg__renderCreate(void* uptr)
{
	return 1;
}

static int glnvg__renderCreateTexture(void* uptr, int type, int w, int h, int imageFlags, const unsigned char* data)
{
	return 1;
}

static int glnvg__renderDeleteTexture(void* uptr, int image)
{
	return 1;
}

static int glnvg__renderUpdateTexture(void* uptr, int image, int x, int y, int w, int h, const unsigned char* data)
{
	return 1;
}

static int glnvg__renderGetTextureSize(void* uptr, int image, int* w, int* h)
{
	*w = 0;
	*h = 0;
	return 1;
}

static void glnvg__renderViewport(void* uptr, int width, int height, float devicePixelRatio)
{}

static void glnvg__renderCancel(void* uptr)
{}

static void glnvg__renderFlush(void* uptr)
{}

static void glnvg__renderFill(void* uptr, NVGpaint* paint, NVGcompositeOperationState compositeOperation, NVGscissor* scissor, const float* xform, float fringe,
							  const float* bounds, const NVGpath* paths, int npaths)
{}

static void glnvg__renderStroke(void* uptr, NVGpaint* paint, NVGcompositeOperationState compositeOperation, NVGscissor* scissor, const float* xform, float fringe,
								float strokeWidth, const float* bounds, const NVGpath* paths, int npaths)
{}

static void glnvg__renderTriangles(void* uptr, NVGpaint* paint, NVGcompositeOperationState compositeOperation, NVGscissor* scissor, const float* xform,
								   const float* bounds, const NVGvertex* verts, int nverts)
{}

static void glnvg__renderDelete(void* uptr)
{}


NVGcontext* nvgCreateNull()
{
	NVGparams params;

	memset(&params, 0, sizeof(params));
	params.renderCreate = glnvg__renderCreate;
	params.renderCreateTexture = glnvg__renderCreateTexture;
	params.renderDeleteTexture = glnvg__renderDeleteTexture;
	params.renderUpdateTexture = glnvg__renderUpdateTexture;
	params.renderGetTextureSize = glnvg__renderGetTextureSize;
	params.renderViewport = glnvg__renderViewport;
	params.renderCancel = glnvg__renderCancel;
	params.renderFlush = glnvg__renderFlush;
	params.renderFill = glnvg__renderFill;
	params.renderStroke = glnvg__renderStroke;
	params.renderTriangles = glnvg__renderTriangles;
	params.renderDelete = glnvg__renderDelete;
	params.edgeAntiAlias = 0;

	NVGcontext* ctx = nvgCreateInternal(&params);
	return ctx;
}

void nvgDeleteNull(NVGcontext* ctx)
{}
#endif

#endif