#sfx
#accompanying library for gfx, enables client-side graphics, usually render over a serial port ("serial graphics")

set(SFX_SRC_DIR ${SONAR_SRC_DIR}/sfx)

set(inc
  dc.h metrics.h graphics.h raster.h vector.h
  object.h sprite.h widget.h layout.h
)

if(SDK)
  file(MAKE_DIRECTORY ${SFX_SRC_DIR})
  install(
    FILES
      ${inc}
    DESTINATION
      ${SFX_SRC_DIR}
  )
endif(SDK)
