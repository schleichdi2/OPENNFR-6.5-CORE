DESCRIPTION = "OPENNFR Image"
SECTION = "base"
PRIORITY = "required"
LICENSE = "proprietary"
MAINTAINER = "OPENNFR team"

require conf/license/license-gplv2.inc

PV = "${IMAGE_VERSION}"
PR = "${BUILD_VERSION}"
PACKAGE_ARCH = "${MACHINE_ARCH}"

do_rootfs[deptask] = "do_rm_work"

IMAGE_INSTALL = "opennfr-base \
	${@bb.utils.contains("MACHINE_FEATURES", "dvbc-only", "", "enigma2-plugin-settings-defaultsat", d)} \
	${@bb.utils.contains("MACHINE_FEATURES", "no-cl-svr", "", \
	" \
	packagegroup-base-smbfs-client \
	packagegroup-base-smbfs-server \
	packagegroup-base-nfs \
	", d)} \
	"

IMAGE_FEATURES += "package-management"

inherit image

image_preprocess() {
			cd ${IMAGE_ROOTFS}/media
			mkdir -p ${IMAGE_ROOTFS}/media/card
			mkdir -p ${IMAGE_ROOTFS}/media/cf
			mkdir -p ${IMAGE_ROOTFS}/media/hdd
			mkdir -p ${IMAGE_ROOTFS}/media/net
			mkdir -p ${IMAGE_ROOTFS}/media/upnp
			mkdir -p ${IMAGE_ROOTFS}/media/usb
			touch ${IMAGE_ROOTFS}/media/hdd/.fstab
			touch ${IMAGE_ROOTFS}/media/usb/.fstab
			cd $curdir
			
			cd ${IMAGE_ROOTFS}/etc
			rm -rf ${IMAGE_ROOTFS}/etc/passwd
			rm -rf ${IMAGE_ROOTFS}/etc/shadow
			mv ${IMAGE_ROOTFS}/etc/passwd-neu ${IMAGE_ROOTFS}/etc/passwd
			mv ${IMAGE_ROOTFS}/etc/shadow-neu ${IMAGE_ROOTFS}/etc/shadow
			rm -rf ${IMAGE_ROOTFS}/etc/passwd-neu
			rm -rf ${IMAGE_ROOTFS}/etc/shadow-neu
			cd $curdir
			
			cd ${IMAGE_ROOTFS}/etc/network	
			rm -rf ${IMAGE_ROOTFS}/etc/network/interfaces
			mv ${IMAGE_ROOTFS}/etc/network/interfaces-neu ${IMAGE_ROOTFS}/etc/network/interfaces
			rm -rf ${IMAGE_ROOTFS}/etc/network/interfaces-neu
			cd $curdir

			cd ${IMAGE_ROOTFS}/usr/emu
				if [ "${TARGET_ARCH}" = "mipsel" ]; then
					rm -rf ${IMAGE_ROOTFS}/usr/emu/oscam
					rm -rf ${IMAGE_ROOTFS}/usr/emu/oscam-emu
					rm -rf ${IMAGE_ROOTFS}/usr/emu/oscam-latest
				else
					rm -rf ${IMAGE_ROOTFS}/usr/emu/oscam-mips
					rm -rf ${IMAGE_ROOTFS}/usr/emu/oscam-mips-emu
				fi
			cd $curdir

}

INHIBIT_DEFAULT_DEPS = "1"

do_package_index[nostamp] = "1"
do_package_index[depends] += "${PACKAGEINDEXDEPS}"

python do_package_index() {
	from oe.rootfs import generate_index_files
	generate_index_files(d)
}

IMAGE_PREPROCESS_COMMAND += "image_preprocess; "

addtask do_package_index after do_rootfs before do_image_complete
