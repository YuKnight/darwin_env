#!/bin/sh

set -ex

# check if we're building for the simulator
[ "${RC_ProjectName%_Sim}" != "${RC_ProjectName}" ] && DSTROOT="$DSTROOT$SDKROOT"

mkdir -m 0755 -p ${DSTROOT}/usr/local/OpenSourceLicenses ${DSTROOT}/usr/local/OpenSourceVersions
install -m 0444 ${SRCROOT}/libarchive.plist ${DSTROOT}/usr/local/OpenSourceVersions/libarchive.plist
install -m 0444 ${SRCROOT}/libarchive/COPYING ${DSTROOT}/usr/local/OpenSourceLicenses/libarchive.txt
