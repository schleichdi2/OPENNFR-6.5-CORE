SUMMARY = "Broadcom VC5 driver"

FILES_${PN} = "${libdir}/lib*${SOLIBSDEV}"
FILES_${PN}-dev = "${includedir}"

EXCLUDE_FROM_WORLD = "1"

INSANE_SKIP_${PN} += "already-stripped dev-so ldflags"
