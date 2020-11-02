SUMMARY = "2nd bootloader support"
SECTION = "base"
PRIORITY = "required"
MAINTAINER = "Gigablue"
LICENSE = "proprietary"
PACKAGE_ARCH := "${MACHINEBUILD}"

require conf/license/license-gplv2.inc

PR = "r3"
ALLOW_EMPTY_${PN} = "1"

do_install() {
    install -d ${D}/usr/share
    install -m 0644 ${WORKDIR}/gpt.bin ${D}/usr/share/gpt.bin
}

FILES_${PN} = "/usr/share"

inherit deploy
do_deploy() {
    if [ -e boot.bin  ]; then
    install -m 0644 boot.bin  ${DEPLOYDIR}/${MACHINEBUILD}_boot.bin
    fi
    if [ -e gpt.bin  ]; then
    install -m 0644 gpt.bin  ${DEPLOYDIR}/${MACHINEBUILD}_gpt.bin
    fi
    if [ -e rescue.bin  ]; then
    install -m 0644 rescue.bin  ${DEPLOYDIR}/${MACHINEBUILD}_rescue.bin
    fi
    if [ -e bolt_${SRCDATE_BOLT}.bin  ]; then
    install -m 0644 bolt_${SRCDATE_BOLT}.bin  ${DEPLOYDIR}/${MACHINEBUILD}_bolt_${SRCDATE_BOLT}.bin
    fi
}

SRC_URI = "http://source.mynonpublic.com/gigablue/initrd/initrd_${MACHINEBUILD}_${SRCDATE}.zip"

S = "${WORKDIR}"

addtask deploy before do_build after do_install