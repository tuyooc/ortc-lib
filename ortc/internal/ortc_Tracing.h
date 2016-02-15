/*

 Copyright (c) 2016, Hookflash Inc.
 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

 1. Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.
 2. Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided with the distribution.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 The views and conclusions contained in the software and documentation are those
 of the authors and should not be interpreted as representing official policies,
 either expressed or implied, of the FreeBSD Project.

 */

#pragma once

#include <ortc/internal/types.h>


#ifdef USE_ETW
#include "ortc_ETWTracing.h"
#else

// Comment the following line to test inline versions of the same macros to test compilation
#define ORTC_USE_NOOP_EVENT_TRACE_MACROS

// NO-OP VERSIONS OF ALL TRACING MACROS
#ifdef ORTC_USE_NOOP_EVENT_TRACE_MACROS

#define EventWriteOrtcCreate(xStr_Method, xPUID)
#define EventWriteOrtcDestroy(xStr_Method, xPUID)

#define EventWriteOrtcCertificateCreate(xStr_Method, xPUID, xStr_KeyGenAlgorithm, xStr_Name, xStr_NamedCurve, xsize_t_KeyLength, xsize_t_RandomBits, xStr_PublicExponenetLength, xlong_long_LifetimeInSeconds, xlong_long_NotBeforeWindowInSeconds, xlong_long_ExpiresInSecondsSinceEpoch)
#define EventWriteOrtcCertificateDestroy(xStr_Method, xPUID)
#define EventWriteOrtcCertificateGenerated(xStr_Method, xPUID, xBool_Success)
#define EventWriteOrtcCertificateFingerprint(xStr_Method, xPUID, xStr_FingerprintAlgorithm, xStr_FingerprintValue)

#define EventWriteOrtcDataChannelCreate(xStr_Method, xPUID, xPUID_DataTransport, xStr_Parameters, xBool_Incoming, xWORD_SessionID)
#define EventWriteOrtcDataChannelDestroy(xStr_Method, xPUID)
#define EventWriteOrtcDataChannelClose(xStr_Method, xPUID)
#define EventWriteOrtcDataChannelCancel(xStr_Method, xPUID)
#define EventWriteOrtcDataChannelStep(xStr_Method, xPUID)
#define EventWriteOrtcDataChannelStateChangedEventFired(xStr_Method, xPUID, xStr_State)
#define EventWriteOrtcDataChannelErrorEventFired(xStr_Method, xPUID, xWORD_Error, xStr_ErrorReason)

#define EventWriteOrtcDataChannelSendControlOpen(xStr_Method, xPUID, xBYTE_MessageType, xBYTE_ChannelType, xWORD_Priority, xDWORD_ReliabilityParameter, xWORD_LabelLength, xWORD_ProtocolLength, xStr_Label, xStr_Protocol)
#define EventWriteOrtcDataChannelSendControlAck(xStr_Method, xPUID, xBYTE_MessageType)

#define EventWriteOrtcDataChannelBufferedAmountLowThresholdChanged(xStr_Method, xPUID, xsize_t_NewThreshold, xsize_t_mOldThreshold, xsize_t_OutgoingBufferFillSize, xBool_BufferedAmountLowThresholdFired)

#define EventWriteOrtcDataChannelSendString(xStr_Method, xPUID, xStr_Data)
#define EventWriteOrtcDataChannelSendBinary(xStr_Method, xPUID, xPtr_Buffer, xsize_t_BufferSizeInBytes)

#define EventWriteOrtcDataChannelOutgoingBufferPacket(xStr_Method, xPUID,  xUInt_Type, xWORD_SessionID, xBool_Ordered, xlong_long_MaxPacketLifetimeInMilliseconds, xBool_HasMaxRetransmits, xDWORD_MaxRetransmits, xPtr_Buffer, xsize_t_BufferSizeInBytes)
#define EventWriteOrtcDataChannelOutgoingBufferPacketDelivered(xStr_Method, xPUID,  xUInt_Type, xWORD_SessionID, xBool_Ordered, xlong_long_MaxPacketLifetimeInMilliseconds, xBool_HasMaxRetransmits, xDWORD_MaxRetransmits, xPtr_Buffer, xsize_t_BufferSizeInBytes)

#define EventWriteOrtcDataChannelReceivedControlOpen(xStr_Method, xPUID, xBool_Incoming, xBYTE_MessageType, xBYTE_ChannelType, xWORD_Priority, xDWORD_ReliabilityParameter, xWORD_LabelLength, xWORD_ProtocolLength, xStr_Label, xStr_Protocol)
#define EventWriteOrtcDataChannelReceivedControlAck(xStr_Method, xPUID, xBYTE_MessageType)

#define EventWriteOrtcDataChannelMessageFiredEvent(xStr_Method, xPUID,  xUInt_Type, xWORD_SessionID, xWORD_SequenceNumber, xDWORD_Timestamp, xInt_Flags, xPtr_Buffer, xsize_t_BufferSizeInBytes)

#define EventWriteOrtcDataChannelSCTPTransportDeliverOutgoingPacket(xStr_Method, xPUID,  xUInt_Type, xWORD_SessionID, xBool_Ordered, xlong_long_MaxPacketLifetimeInMilliseconds, xBool_HasMaxRetransmits, xDWORD_MaxRetransmits, xPtr_Buffer, xsize_t_BufferSizeInBytes)

#define EventWriteOrtcDataChannelSCTPTransportRequestShutdown(xStr_Method, xPUID)
#define EventWriteOrtcDataChannelSCTPTransportRequestNotifyClosed(xStr_Method, xPUID)
#define EventWriteOrtcDataChannelSCTPTransportStateChanged(xStr_Method, xPUID)
#define EventWriteOrtcDataChannelSCTPTransportSendReady(xStr_Method, xPUID)
#define EventWriteOrtcDataChannelSCTPTransportSendReadyFailure(xStr_Method, xPUID, xWORD_Error, xStr_ErrorReason)
#define EventWriteOrtcDataChannelSCTPTransportReceivedIncomingPacket(xStr_Method, xPUID,  xUInt_Type, xWORD_SessionID, xWORD_SequenceNumber, xDWORD_Timestamp, xInt_Flags, xPtr_Buffer, xsize_t_BufferSizeInBytes)

#define EventWriteOrtcDtlsTransportCreate(xStr_Method, xPUID, xPUID_IceTransport, xStr_Component, xsize_t_MaxPendingDTLSBuffer, xsize_t_MaxPendingRTPPackets, xsize_t_TotalCertificates)
#define EventWriteOrtcDtlsTransportDestroy(xStr_Method, xPUID)
#define EventWriteOrtcDtlsTransportInitization(xStr_Method, xPUID, xPUID_IceTransport, xPUID_RtpListener, xsize_t_TotalCiphers, xsize_t_TotalFingerprints)
#define EventWriteOrtcDtlsTransportStep(xStr_Method, xPUID)
#define EventWriteOrtcDtlsTransportCancel(xStr_Method, xPUID)

#define EventWriteOrtcDtlsTransportInitizationInstallCipher(xStr_Method, xPUID, xStr_Cipher)
#define EventWriteOrtcDtlsTransportInitizationInstallFingerprint(xStr_Method, xPUID, xStr_Algorithm, xStr_Value, xBool_IsLocal)

#define EventWriteOrtcDtlsTransportStart(xStr_Method, xPUID, xStr_Role, xsize_t_TotalFingerprints)
#define EventWriteOrtcDtlsTransportStop(xStr_Method, xPUID)

#define EventWriteOrtcDtlsTransportRoleSet(xStr_Method, xPUID, xStr_Role)

#define EventWriteOrtcDtlsTransportReceivedPacket(xStr_Method, xPUID, xUInt_ViaTransport, xBool_IsDtlsPacket, xPtr_Buffer, xsize_t_BufferSizeInBytes)
#define EventWriteOrtcDtlsTransportReceivedStunPacket(xStr_Method, xPUID, xUInt_ViaTransport)

#define EventWriteOrtcDtlsTransportForwardingEncryptedPacketToSrtpTransport(xStr_Method, xPUID, xPUID_SrtpTransportObjectID, xUInt_ViaTransport, xPtr_Buffer, xsize_t_BufferSizeInBytes)
#define EventWriteOrtcDtlsTransportForwardingPacketToDataTransport(xStr_Method, xPUID, xPUID_DataTransportObjectID, xUInt_ViaTransport, xPtr_Buffer, xsize_t_BufferSizeInBytes)
#define EventWriteOrtcDtlsTransportForwardingPacketToRtpListener(xStr_Method, xPUID, xPUID_RtpListenerObjectID, xUInt_ViaTransport,  xUInt_PacketType, xPtr_Buffer, xsize_t_BufferSizeInBytes)

#define EventWriteOrtcDtlsTransportSendRtpPacket(xStr_Method, xPUID, xUInt_SendOverComponent, xUInt_PacketType, xPtr_Buffer, xsize_t_BufferSizeInBytes)
#define EventWriteOrtcDtlsTransportSendDataPacket(xStr_Method, xPUID, xPtr_Buffer, xsize_t_BufferSizeInBytes)
#define EventWriteOrtcDtlsTransportForwardDataPacketToIceTransport(xStr_Method, xPUID, xPUID_IceTransportObjectID, xPtr_Buffer, xsize_t_BufferSizeInBytes)

#define EventWriteOrtcDtlsTransportSendEncryptedRtpPacket(xStr_Method, xPUID, xPUID_IceTransportObjectID, xUInt_SendOverComponent, xUInt_PacketType, xPtr_Buffer, xsize_t_BufferSizeInBytes)

#define EventWriteOrtcDtlsTransportInternalTimerEventFired(xStr_Method, xPUID, xPUID_TimerID)
#define EventWriteOrtcDtlsTransportInternalIceStateChangeEventFired(xStr_Method, xPUID, xPUID_IceTransportObjectID, xStr_State)
#define EventWriteOrtcDtlsTransportInternalSrtpTransportLifetimeRemainingEventFired(xStr_Method, xPUID, xPUID_SrtpTransportObjectID, xULONG_LeastLifetimeRemainingPercentageForAllKeys, xULONG_OverallLifetimeRemainingPercentage)

#define EventWriteOrtcDtlsTransportStateChangedEventFired(xStr_Method, xPUID, xStr_State)
#define EventWriteOrtcDtlsTransportErrorEventFired(xStr_Method, xPUID, xWORD_Error, xStr_ErrorReason)

#define EventWriteOrtcDtlsTransportSrtpKeyingMaterialSetup(xStr_Method, xPUID, xPUID_SecureTransportObjectID, xStr_Direction, xStr_Cipher, xPtr_KeyingMaterialBuffer, xsize_t_KeyingMaterialBufferSizeInBytes)

#define EventWriteOrtcIceGathererCreate(xStr_Method, xPUID, xPUID_GethererRouterObjectID, xStr_UsernameFragment, xStr_Password, xBool_CreateTCPCandidates, xBool_ContinousGathering, xsize_t_TotalInterfacePolicies, xsize_t_TotalIceServers, xlong_long_ReflexiveInactivityTimeInSeconds, xlong_long_RelayInactivityTimeInSeoncds, xlong_long_MaxBufferingTimeInSeconds, xlong_long_RecheckIPsInSeconds, xsize_t_MaxTotalBuffers, xsize_t_MaxTCPBufferingSizePendingConnectionInBytes, xsize_t_MaxTCPBufferingSizeConnectedInBytes, xBool_GatherPassiveTCP)
#define EventWriteOrtcIceGathererDestroy(xStr_Method, xPUID)
#define EventWriteOrtcIceGathererStep(xStr_Method, xPUID)
#define EventWriteOrtcIceGathererCancel(xStr_Method, xPUID)
#define EventWriteOrtcIceGathererCreatedAssociateGatherer(xStr_Method, xPUID, xPUID_AssociatedGathererObjectID)

#define EventWriteOrtcIceGathererInitializeInstallInterfaceNameMapping(xStr_Method, xPUID, xStr_InterfaceNameRegularExpresssion, xStr_InterfaceType, xULONG_OrderIndex)
#define EventWriteOrtcIceGathererInitializeInstallPreference(xStr_Method, xPUID, xStr_PreferenceType, xStr_Preference, xStr_SubPreference, xDWORD_PreferenceValue)

#define EventWriteOrtcIceGathererGather(xStr_Method, xPUID, xBool_ContinuousGathering, xsize_t_TotalInterfacePolicies, xsize_t_TotalIceServers)

#define EventWriteOrtcIceGathererStateChangedEventFired(xStr_Method, xPUID, xStr_State)
#define EventWriteOrtcIceGathererErrorEventFired(xStr_Method, xPUID, xWORD_Error, xStr_Reason)

#define EventWriteOrtcIceGathererAddCandidateEventFired(xStr_Method, xPUID, xStr_LocalHash, xStr_NotifyHash, xStr_InterfaceType, xStr_Foundation, xDWORD_Priority, xDWORD_UnfreezePriority, xStr_Protocol, xStr_IP, xWORD_Port, xStr_CandidateType, xStr_TcpType, xStr_RelatedAddress, xWORD_RelatedPort)
#define EventWriteOrtcIceGathererRemoveCandidateEventFired(xStr_Method, xPUID, xStr_LocalHash, xStr_NotifyHash, xStr_InterfaceType, xStr_Foundation, xDWORD_Priority, xDWORD_UnfreezePriority, xStr_Protocol, xStr_IP, xWORD_Port, xStr_CandidateType, xStr_TcpType, xStr_RelatedAddress, xWORD_RelatedPort)
#define EventWriteOrtcIceGathererFilterCandidateEventFired(xStr_Method, xPUID,  xUInt_FilterPolicy, xStr_BoundIP, xStr_InterfaceType, xStr_Foundation, xDWORD_Priority, xDWORD_UnfreezePriority, xStr_Protocol, xStr_IP, xWORD_Port, xStr_CandidateType, xStr_TcpType, xStr_RelatedAddress, xWORD_RelatedPort)

#define EventWriteOrtcIceGathererInstallIceTransport(xStr_Method, xPUID, xPUID_IceTransportObjectID, xStr_RemoteUsernameFragment)
#define EventWriteOrtcIceGathererRemoveIceTransport(xStr_Method, xPUID, xPUID_IceTransportObjectID)
#define EventWriteOrtcIceGathererInternalIceTransportStateChangedEventFired(xStr_Method, xPUID, xPUID_IceTransportObjectID)

#define EventWriteOrtcIceGathererRemovetAllIceTransportRelatedRoutes(xStr_Method, xPUID, xPUID_IceTransportObjectID)
#define EventWriteOrtcIceGathererSendIceTransportPacket(xStr_Method, xPUID, xPUID_IceTransportObjectID, xPUID_RouteID, xPtr_Buffer, xsize_t_BufferSizeInBytes)
#define EventWriteOrtcIceGathererSendIceTransportPacketFailed(xStr_Method, xPUID, xPUID_IceTransportObjectID, xPUID_RouteID, xPtr_Buffer, xsize_t_BufferSizeInBytes)

#define EventWriteOrtcIceGathererSendIceTransportPacketViaUdp(xStr_Method, xPUID, xPUID_IceTransportObjectID, xPUID_RouteID, xPUID_HostPortObjectID, xStr_RemoteIP, xPtr_Buffer, xsize_t_BufferSizeInBytes)
#define EventWriteOrtcIceGathererSendIceTransportPacketViaTcp(xStr_Method, xPUID, xPUID_IceTransportObjectID, xPUID_RouteID, xPUID_TcpPortObjectID, xPtr_Buffer, xsize_t_BufferSizeInBytes)
#define EventWriteOrtcIceGathererSendIceTransportPacketViaTurn(xStr_Method, xPUID, xPUID_IceTransportObjectID, xPUID_RouteID, xPUID_TurnObjectID, xPtr_Buffer, xsize_t_BufferSizeInBytes)

#define EventWriteOrtcIceGathererDeliverIceTransportIncomingPacket(xStr_Method, xPUID, xPUID_IceTransportObjectID, xPUID_RouteID, xPUID_xRouterRouteID, xBool_WasBuffered, xPtr_Buffer, xsize_t_BufferSizeInBytes)
#define EventWriteOrtcIceGathererBufferIceTransportIncomingPacket(xStr_Method, xPUID, xPUID_xRouterRouteID, xPtr_Buffer, xsize_t_BufferSizeInBytes)

#define EventWriteOrtcIceGathererDeliverIceTransportIncomingStunPacket(xStr_Method, xPUID, xPUID_IceTransportObjectID, xPUID_RouteID, xPUID_xRouterRouteID, xBool_WasBuffered)
#define EventWriteOrtcIceGathererBufferIceTransportIncomingStunPacket(xStr_Method, xPUID, xPUID_xRouterRouteID)
#define EventWriteOrtcIceGathererErrorIceTransportIncomingStunPacket(xStr_Method, xPUID, xPUID_IceTransportObjectID, xPUID_RouteID, xPUID_xRouterRouteID)

#define EventWriteOrtcIceGathererDisposeBufferedIceTransportIncomingPacket(xStr_Method, xPUID, xPUID_xRouterRouteID, xPtr_Buffer, xsize_t_BufferSizeInBytes)
#define EventWriteOrtcIceGathererDisposeBufferedIceTransportIncomingStunPacket(xStr_Method, xPUID, xPUID_xRouterRouteID)

#define EventWriteOrtcIceGathererTurnSocketReceivedPacket(xStr_Method, xPUID, xPUID_TurnSocketObjectID, xPtr_Buffer, xsize_t_BufferSizeInBytes)
#define EventWriteOrtcIceGathererTurnSocketSendPacket(xStr_Method, xPUID, xPUID_TurnSocketObjectID, xPtr_Buffer, xsize_t_BufferSizeInBytes)

#define EventWriteOrtcIceGathererInstallQuickRoute(xStr_Method, xPUID, xPtr_Candidate, xStr_IPAddress, xPUID_RouteID)
#define EventWriteOrtcIceGathererRemoveQuickRoute(xStr_Method, xPUID, xPtr_Candidate, xStr_IPAddress, xPUID_RouteID)
#define EventWriteOrtcIceGathererSearchQuickRoute(xStr_Method, xPUID, xPtr_Candidate, xStr_IPAddress, xBool_Found)

#define EventWriteOrtcIceGathererInternalWakeEventFired(xStr_Method, xPUID)
#define EventWriteOrtcIceGathererInternalDnsLoookupCompleteEventFired(xStr_Method, xPUID, xPUID_QueryID)
#define EventWriteOrtcIceGathererInternalTimerEventFired(xStr_Method, xPUID, xPUID_TimerID, xStr_TimerType, xPUID_RelatedObjectID)
#define EventWriteOrtcIceGathererInternalLikelyReflexiveActivityEventFired(xStr_Method, xPUID, xPUID_RouteID, xPUID_xRouterRouteID)

#define EventWriteOrtcIceGathererInternalSocketReadReadyEventFired(xStr_Method, xPUID, xRelatedObjectID)
#define EventWriteOrtcIceGathererInternalSocketWriteReadyEventFired(xStr_Method, xPUID, xRelatedObjectID)
#define EventWriteOrtcIceGathererInternalSocketExceptionEventFired(xStr_Method, xPUID, xRelatedObjectID)

#define EventWriteOrtcIceGathererInternalBackOffTimerStateChangedEventFired(xStr_Method, xPUID, xPUID_BackOffTimerObjectID, xStr_State)

#define EventWriteOrtcIceGathererInternalStunDiscoverySendPacket(xStr_Method, xPUID, xPUID_StunDiscoveryObjectID, xStr_DestinationIP, xPtr_Buffer, xsize_t_BufferSizeInBytes)
#define EventWriteOrtcIceGathererInternalStunDiscoveryCompleteEventFired(xStr_Method, xPUID, xPUID_StunDiscoveryObjectID, xPUID_HostPortObjectID, xStr_MappedIP)

#define EventWriteOrtcIceGathererInternalTurnSocketStateChangeEventFired(xStr_Method, xPUID, xPUID_TurnSocketObjectID, xStr_State)

#define EventWriteOrtcIceGathererResolveHostIP(xStr_Method, xPUID, xPUID_DnsQueryID, xStr_HostName)
#define EventWriteOrtcIceGathererResolveFoundHostIP(xStr_Method, xPUID, xStr_HostIP, xStr_HostName, xStr_InterfaceName, xULONG_AdapterSpecific)

#define EventWriteOrtcIceGathererPendingResolveHostIP(xStr_Method, xPUID, xStr_ProfileName, xStr_HostName, xStr_IP)

#define EventWriteOrtcIceGathererHostPortCreate(xStr_Method, xPUID, xPUID_HostPortObjectID, xStr_HostIP)
#define EventWriteOrtcIceGathererHostPortDestroy(xStr_Method, xPUID, xPUID_HostPortObjectID, xStr_HostIP)
#define EventWriteOrtcIceGathererHostPortBind(xStr_Method, xPUID, xPUID_HostPortObjectID, xStr_HostIP, Str_ProtocolType, xBool_Success)
#define EventWriteOrtcIceGathererHostPortClose(xStr_Method, xPUID, xPUID_HostPortObjectID, xStr_HostIP, Str_ProtocolType)

#define EventWriteOrtcIceGathererReflexivePortCreate(xStr_Method, xPUID, xPUID_ReflexivePortObjectID, xStr_Server)
#define EventWriteOrtcIceGathererReflexivePortDestroy(xStr_Method, xPUID, xPUID_ReflexivePortObjectID, xStr_Server)
#define EventWriteOrtcIceGathererReflexivePortFoundMapped(xStr_Method, xPUID, xPUID_ReflexivePortObjectID, xStr_MappedIP)

#define EventWriteOrtcIceGathererRelayPortCreate(xStr_Method, xPUID, xPUID_RelayPortObjectID, xStr_Server, xStr_Username, xStr_Credential, xStr_CredentialType)
#define EventWriteOrtcIceGathererRelayPortDestroy(xStr_Method, xPUID, xPUID_RelayPortObjectID, xStr_Server)
#define EventWriteOrtcIceGathererRelayPortFoundIP(xStr_Method, xPUID, xPUID_RelayPortObjectID, xStr_CandidateType, xStr_IP)

#define EventWriteOrtcIceGathererTcpPortCreate(xStr_Method, xPUID, xPUID_TcpPortObjectID, xStr_RemoteIP)
#define EventWriteOrtcIceGathererTcpPortDestroy(xStr_Method, xPUID, xPUID_TcpPortObjectID, xStr_RemoteIP)

#define EventWriteOrtcIceGathererUdpSocketPacketReceivedFrom(xStr_Method, xPUID, xStr_FromIP, xPtr_Buffer, xsize_t_BufferSizeInBytes)
#define EventWriteOrtcIceGathererUdpSocketPacketForwardingToTurnSocket(xStr_Method, xPUID, xStr_FromIP, xBool_IsStun, xPtr_Buffer, xsize_t_BufferSizeInBytes)
#define EventWriteOrtcIceGathererUdpSocketPacketSentTo(xStr_Method, xPUID, xStr_BoundIP, xStr_ToIP, xPtr_Buffer, xsize_t_BufferSizeInBytes)

#define EventWriteOrtcIceGathererTcpSocketPacketReceivedFrom(xStr_Method, xPUID, xStr_FromIP, xPtr_Buffer, xsize_t_BufferSizeInBytes)
#define EventWriteOrtcIceGathererTcpSocketSentOutgoing(xStr_Method, xPUID, xStr_FromIP, xPtr_Buffer, xsize_t_BufferSizeInBytes)

#define EventWriteOrtcIceGathererRouteTrace(xStr_Method, xStr_CallingMethod, xStr_Message, xGathererRouteObjectID, xPUID_GathererObjectID, xlong_long_LastUsedInMillisecondsSinceEpoch, xPUID_IceTransportObjectID, xPUID_HostPortObjectID, xPUID_RelayPortObjectID, xPUID_TcpPortObjectID, xStr_LocalInterfaceType, xStr_LocalFoundation, xDWORD_LocalPriority, xDWORD_LocalUnfreezePriority, xStr_LocalProtocol, xStr_LocalIP, xWORD_LocalPort, xStr_LocalCandidateType, xStr_LocalTcpType, xStr_LocalRelatedAddress, xWORD_LocalRelatedPort)

#define EventWriteOrtcIceGathererRouterCreate(xStr_Method, xPUID)
#define EventWriteOrtcIceGathererRouterDestroy(xStr_Method, xPUID)
#define EventWriteOrtcIceGathererRouterCancel(xStr_Method, xPUID)
#define EventWriteOrtcIceGathererRouterInternalEvent(xStr_Method, xPUID, xStr_Event, xStr_CandidateHash, xStr_LocalCandidateIP, xWORD_LocalCandidatePort, xStr_RemoteIP)

#define EventWriteOrtcIceGathererRouterRouteTrace(xStr_Method, xStr_CallingMethod, xStr_Message, xGathererRouterRouteObjectID, xStr_LocalInterfaceType, xStr_LocalFoundation, xDWORD_LocalPriority, xDWORD_LocalUnfreezePriority, xStr_LocalProtocol, xStr_LocalIP, xWORD_LocalPort, xStr_LocalCandidateType, xStr_LocalTcpType, xStr_LocalRelatedAddress, xWORD_LocalRelatedPort, xStr_RemoteIP)

#define EventWriteOrtcIceTransportCreate(xStr_Method, xPUID, xPUID_GathererObjectID, xPUID_GathererRouterObjectID, xlong_long_NoPacketReceivedRecheckTimeInSeconds, xlong_long_ExpireRouteInSeconds, xBool_TestLowerPreferenceCandidatePairs, xBool_BlacklistConsent, xlong_long_KeepWarmTimeBaseInMilliseconds, xlong_long_KeepWarmTimeRandomAddTimeInMilliseconds, xsize_t_MaxBufferedPackets, xQWORD_ConflictResolver)
#define EventWriteOrtcIceTransportDestroy(xStr_Method, xPUID)
#define EventWriteOrtcIceTransportStep(xStr_Method, xPUID)
#define EventWriteOrtcIceTransportCancel(xStr_Method, xPUID)

#define EventWriteOrtcIceTransportRouteStateTrackerStateCountChange(xStr_Method, xPUID_IceTransportObjectID, xStr_State, xsize_t_Value)

#define EventWriteOrtcIceTransportStart(xStr_Method, xPUID, xPUID_GathererObjectID, xBool_RemoteUseCandidateFreezePriority, xStr_RemoteUsernameFragment, xStr_RemotePassword, xBool_IceLite, xStr_RemoteParametersHash, xStr_OldRemoteParametersHash, xBool_HasRemoteUsernameFragment)
#define EventWriteOrtcIceTransportCreateAssociatedTransport(xStr_Method, xPUID, xPUID_AssociatedTransportObjectID)

#define EventWriteOrtcIceTransportAddRemoteCandidate(xStr_Method, xPUID, xStr_Hash, xStr_InterfaceType, xStr_Foundation, xDWORD_Priority, xDWORD_UnfreezePriority, xStr_Protocol, xStr_IP, xWORD_Port, xStr_CandidateType, xStr_TcpType, xStr_RelatedAddress, xWORD_RelatedPort, xBool_PreviouslyAdded)
#define EventWriteOrtcIceTransportAddRemoteCandidateComplete(xStr_Method, xPUID)
#define EventWriteOrtcIceTransportRemoveRemoteCandidate(xStr_Method, xPUID, xStr_Hash, xStr_InterfaceType, xStr_Foundation, xDWORD_Priority, xDWORD_UnfreezePriority, xStr_Protocol, xStr_IP, xWORD_Port, xStr_CandidateType, xStr_TcpType, xStr_RelatedAddress, xWORD_RelatedPort, xBool_WasKnownPreviously)
#define EventWriteOrtcIceTransportRemoveRemoteCandidateComplete(xStr_Method, xPUID)

#define EventWriteOrtcIceTransportKeepWarm(xStr_Method, xPUID, xStr_Reason, xStr_CandidatePairHash, xBool_KeepWarm)

#define EventWriteOrtcIceTransportStateChangedEventFired(xStr_Method, xPUID, xStr_State)
#define EventWriteOrtcIceTransportErrorEventFired(xStr_Method, xPUID, xWORD_Error, xStr_State)
#define EventWriteOrtcIceTransportCandidatePairChangedEventFired(xStr_Method, xPUID, xPUID_RouteObjectID)

#define EventWriteOrtcIceTransportRouteTrace(xStr_Method, xStr_CallingMethod, xStr_Message, xTransportRouteObjectID, xPUID_IceTransportObjectID, xStr_CandidatePairHash, xStr_LocalInterfaceType, xStr_LocalFoundation, xDWORD_LocalPriority, xDWORD_LocalUnfreezePriority, xStr_LocalProtocol, xStr_LocalIP, xWORD_LocalPort, xStr_LocalCandidateType, xStr_LocalTcpType, xStr_LocalRelatedAddress, xWORD_LocalRelatedPort, xStr_RemoteInterfaceType, xStr_RemoteFoundation, xDWORD_RemotePriority, xDWORD_RemoteUnfreezePriority, xStr_RemoteProtocol, xStr_RemoteIP, xWORD_RemotePort, xStr_RemoteCandidateType, xStr_RemoteTcpType, xStr_RemoteRelatedAddress, xWORD_RemoteRelatedPort, xPUID_GathererRouteObjectID, xQWORD_PendingPriority, xlong_long_LastReceivedCheckTimeInMillisecondsSinceEpoch, xlong_long_LastSentCheckTimeInMillisecondsSinceEpoch, xlong_long_LastReceivedMediaTimeInMillisecondsSinceEpoch, xlong_long_LastReceivedResponseTimeInMillisecondsSinceEpoch, xBool_Prune, xBool_KeepWarm, xPUID_OutgoingCheckStunRequesterObjectID, xPUID_NextKeepWarmTimerObjectID, xBool_FrozenPromise, xsize_t_TotalDependentPromises, xlong_long_LastRoundTripCheckInMillisecondsSinceEpoch, xlong_long_LastRoundTripMeasurementInMilliseconds)

#define EventWriteOrtcIceTransportReceivedPacketFromGatherer(xStr_Method, xPUID, xPUID_RouterRouteObjectID, xPtr_Buffer, xsize_t_BufferSizeInBytes)
#define EventWriteOrtcIceTransportReceivedStunPacketFromGatherer(xStr_Method, xPUID, xPUID_RouterRouteObjectID)
#define EventWriteOrtcIceTransportRetryReceivedStunPacketFromGatherer(xStr_Method, xPUID, xPUID_RouterRouteObjectID)

#define EventWriteOrtcIceTransportBufferingIncomingPacket(xStr_Method, xPUID, xPtr_Buffer, xsize_t_BufferSizeInBytes)
#define EventWriteOrtcIceTransportDisposingBufferedIncomingPacket(xStr_Method, xPUID, xPtr_Buffer, xsize_t_BufferSizeInBytes)
#define EventWriteOrtcIceTransportDeliveringBufferedIncomingPacketToSecureTransport(xStr_Method, xPUID, xPUID_SecureTransportObjectID, xPtr_Buffer, xsize_t_BufferSizeInBytes)

#define EventWriteOrtcIceTransportDeliveringIncomingPacketToSecureTransport(xStr_Method, xPUID, xPUID_SecureTransportObjectID, xPtr_Buffer, xsize_t_BufferSizeInBytes)
#define EventWriteOrtcIceTransportDeliveringIncomingStunPacketToSecureTransport(xStr_Method, xPUID, xPUID_SecureTransportObjectID)

#define EventWriteOrtcIceTransportInstallFoundation(xStr_Method, xPUID, xStr_LocalFoundation, xStr_RemoteFoundation, xsize_t_TotalRoutes)
#define EventWriteOrtcIceTransportRemoveFoundation(xStr_Method, xPUID, xStr_LocalFoundation, xStr_RemoteFoundation, xsize_t_TotalRoutes)
#define EventWriteOrtcIceTransportInstallFoundationDependencyFreezePromise(xStr_Method, xPUID, xStr_LocalFoundation, xStr_RemoteFoundation)

#define EventWriteOrtcIceTransportSecureTransportSendPacket(xStr_Method, xPUID, xPtr_Buffer, xsize_t_BufferSizeInBytes)
#define EventWriteOrtcIceTransportForwardSecureTransportPacketToGatherer(xStr_Method, xPUID, xPUID_GathererObjectID, xPtr_Buffer, xsize_t_BufferSizeInBytes)

#define EventWriteOrtcIceTransportSendStunPacket(xStr_Method, xPUID, xPUID_GathererObjectID, xPtr_Buffer, xsize_t_BufferSizeInBytes)

#define EventWriteOrtcIceTransportInternalControllerAttachedEventFired(xStr_Method, xPUID, xPUID_IceTransportControllerObjectID)
#define EventWriteOrtcIceTransportInternalControllerDetachedEventFired(xStr_Method, xPUID, xPUID_IceTransportControllerObjectID)

#define EventWriteOrtcIceTransportInternalSecureTransportAttachedEventFired(xStr_Method, xPUID, xPUID_SecureTransportObjectID)
#define EventWriteOrtcIceTransportInternalSecureTransportDetachedEventFired(xStr_Method, xPUID, xPUID_SecureTransportObjectID)

#define EventWriteOrtcIceTransportInternalWarmRoutesChangedEventFired(xStr_Method, xPUID)
#define EventWriteOrtcIceTransportInternalDeliveryPendingPacketsEventFired(xStr_Method, xPUID)

#define EventWriteOrtcIceTransportInternalWakeEventFired(xStr_Method, xPUID)
#define EventWriteOrtcIceTransportInternalTimerEventFired(xStr_Method, xPUID, xPUID_TimerID, xStr_TimerType)

#define EventWriteOrtcIceTransportInternalUnfrozenPromiseEventFired(xStr_Method, xPUID, xPUID_RouteObjectID)

#define EventWriteOrtcIceTransportInternalGathererStateChangedEventFired(xStr_Method, xPUID, xPUID_GathererObjectID, xStr_State)
#define EventWriteOrtcIceTransportInternalGathererAddLocalCandidateEventFired(xStr_Method, xPUID, xPUID_GathererObjectID, xStr_InterfaceType, xStr_Foundation, xDWORD_Priority, xDWORD_UnfreezePriority, xStr_Protocol, xStr_IP, xWORD_Port, xStr_CandidateType, xStr_TcpType, xStr_RelatedAddress, xWORD_RelatedPort)
#define EventWriteOrtcIceTransportInternalGathererAddLocalCandidateCompleteEventFired(xStr_Method, xPUID, xPUID_GathererObjectID)
#define EventWriteOrtcIceTransportInternalGathererRemoveLocalCandidateEventFired(xStr_Method, xPUID, xPUID_GathererObjectID, xStr_InterfaceType, xStr_Foundation, xDWORD_Priority, xDWORD_UnfreezePriority, xStr_Protocol, xStr_IP, xWORD_Port, xStr_CandidateType, xStr_TcpType, xStr_RelatedAddress, xWORD_RelatedPort)

#define EventWriteOrtcIceTransportInternalStunRequesterCreate(xStr_Method, xPUID, xPUID_StunRequesterObjectID)
#define EventWriteOrtcIceTransportInternalStunRequesterSendPacket(xStr_Method, xPUID, xPUID_StunRequesterObjectID, xStr_DestinationIP, xPtr_Buffer, xsize_t_BufferSizeInBytes)
#define EventWriteOrtcIceTransportInternalStunRequesterReceivedResponse(xStr_Method, xPUID, xPUID_StunRequesterObjectID, xStr_FromIP)
#define EventWriteOrtcIceTransportInternalStunRequesterReceivedResponseMismatch(xStr_Method, xPUID, xPUID_StunRequesterObjectID, xStr_FromIP, xStr_ExpectingIP)
#define EventWriteOrtcIceTransportInternalStunRequesterTimedOut(xStr_Method, xPUID, xPUID_StunRequesterObjectID)

#define EventWriteOrtcIceTransportInternalRoleConflictDetectedEventFired(xStr_Method, xPUID, xStr_NewRole, xStr_Reason)

#define EventWriteOrtcIceTransportControllerCreate(xStr_Method, xPUID)
#define EventWriteOrtcIceTransportControllerDestroy(xStr_Method, xPUID)
#define EventWriteOrtcIceTransportControllerCancel(xStr_Method, xPUID)
#define EventWriteOrtcIceTransportControllerStep(xStr_Method, xPUID)

#define EventWriteOrtcIceTransportControllerInternalWakeEventFired(xStr_Method, xPUID)
#define EventWriteOrtcIceTransportControllerInternalTransportAttachedEventFired(xStr_Method, xPUID, xPUID_IceTransportObjectID, xsize_t_AttachedOrderID, xBool_HasInsertIndex, xsize_t_InsertIndex)
#define EventWriteOrtcIceTransportControllerInternalTransportDetachedEventFired(xStr_Method, xPUID, xPUID_IceTransportObjectID, xsize_t_DetachedOrderID)

#define EventWriteOrtcIceTransportControllerWaitUntilUnfrozen(xStr_Method, xPUID, xPUID_IceTransportObjectID, xStr_LocalFoundation, xStr_RemoteFoundation)
#define EventWriteOrtcIceTransportControllerNoNeedToWaitUntilUnfrozen(xStr_Method, xPUID, xPUID_IceTransportObjectID, xStr_LocalFoundation, xStr_RemoteFoundation)

#define EventWriteOrtcRtpListenerCreate(xStr_Method, xPUID, xPUID_RtpTransport, xsize_t_MaxBufferedRtpPackets, xlong_long_MaxRtpPacketAgeInSeconds, xsize_t_MaxBufferedRtcpPackets, xlong_long_AmbigousPayloadMappingMinDifferenceInMilliseconds, xlong_long_SsrcTableExpiresInSeconds, xlong_long_UnhandledEventsExpiresInSeconds)
#define EventWriteOrtcRtpListenerDestroy(xStr_Method, xPUID)
#define EventWriteOrtcRtpListenerCancel(xStr_Method, xPUID)
#define EventWriteOrtcRtpListenerStep(xStr_Method, xPUID)
#define EventWriteOrtcRtpListenerFindMapping(xStr_Method, xPUID, xStr_MuxID, xPtr_Buffer, xsize_t_BufferSizeInBytes)
#define EventWriteOrtcRtpListenerFoundMappingByMuxID(xStr_Method, xPUID, xPUID_RtpReceiverObjectID, xStr_MuxID)
#define EventWriteOrtcRtpListenerFoundMappingBySsrc(xStr_Method, xPUID, xPUID_RtpReceiverObjectID, xDWORD_Ssrc)
#define EventWriteOrtcRtpListenerFoundMappingByPayloadType(xStr_Method, xPUID, xPUID_RtpReceiverObjectID, xBYTE_PayloadType)

#define EventWriteOrtcRtpListenerStateChangedEventFired(xStr_Method, xPUID, xStr_State)
#define EventWriteOrtcRtpListenerErrorEventFired(xStr_Method, xPUID, xWORD_ErrorCode, xStr_ErrorReason)
#define EventWriteOrtcRtpListenerUnhandledEventFired(xStr_Method, xPUID, xStr_MuxID, xStr_Rid, xDWORD_Ssrc, xBYTE_PayloadType)

#define EventWriteOrtcRtpListenerRegisterHeaderExtension(xStr_Method, xPUID, xPUID_RegisterForObject, xStr_ExtensionURI, xunsigned_short_LocalID, xBool_Encrypted, xsize_t_TotalReferences)
#define EventWriteOrtcRtpListenerUnregisterHeaderExtension(xStr_Method, xPUID, xPUID_RegisterForObject, xStr_ExtensionURI, xunsigned_short_LocalID, xBool_Encrypted, xsize_t_TotalReferences)

#define EventWriteOrtcRtpListenerReceivedIncomingPacket(xStr_Method, xPUID, xUInt_ViaComponent, xUInt_PacketType, xPtr_Buffer, xsize_t_BufferSizeInBytes)
#define EventWriteOrtcRtpListenerBufferIncomingPacket(xStr_Method, xPUID, xUInt_ViaComponent, xUInt_PacketType, xPtr_Buffer, xsize_t_BufferSizeInBytes)
#define EventWriteOrtcRtpListenerForwardIncomingPacket(xStr_Method, xPUID, xPUID_SenderOrReceiverObjectID, xUInt_ViaComponent, xUInt_PacketType, xPtr_Buffer, xsize_t_BufferSizeInBytes)
#define EventWriteOrtcRtpListenerDisposeBufferedIncomingPacket(xStr_Method, xPUID, xUInt_PacketType, xPtr_Buffer, xsize_t_BufferSizeInBytes)

#define EventWriteOrtcRtpListenerRegisterReceiver(xStr_Method, xPUID, xPUID_RtpReceiverObjectID, xPUID_OrderID, xStr_Kind)
#define EventWriteOrtcRtpListenerUnregisterReceiver(xStr_Method, xPUID, xPUID_RtpReceiverObjectID)

#define EventWriteOrtcRtpListenerRegisterSender(xStr_Method, xPUID, xPUID_RtpSenderObjectID)
#define EventWriteOrtcRtpListenerUnregisterSender(xStr_Method, xPUID, xPUID_RtpSenderObjectID)

#define EventWriteOrtcRtpListenerInternalWakeEventFired(xStr_Method, xPUID)
#define EventWriteOrtcRtpListenerInternalTimerEventFired(xStr_Method, xPUID, xPUID_TimerID, xStr_TimerType)

#define EventWriteOrtcRtpListenerSsrcTableEntryAdded(xStr_Method, xPUID, xPUID_RtpReceiverObjectID, xDWORD_Ssrc, xlong_long_LastUsageSinceEpochInSeconds, xStr_MuxID)
#define EventWriteOrtcRtpListenerSsrcTableEntryRemoved(xStr_Method, xPUID, xPUID_RtpReceiverObjectID, xDWORD_Ssrc, xlong_long_LastUsageSinceEpochInSeconds, xStr_MuxID, xStr_Reason)
#define EventWriteOrtcRtpListenerSsrcTableEntryUpdated(xStr_Method, xPUID, xPUID_RtpReceiverObjectID, xDWORD_Ssrc, xlong_long_LastUsageSinceEpochInSeconds, xStr_MuxID)


#else

// duplicate testing compilation methods used to verify compilation when macros get defined
namespace ortc
{

inline void EventWriteOrtcCreate(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcDestroy(const char *xStr_Method, PUID xPUID) {}

inline void EventWriteOrtcCertificateCreate(const char *xStr_Method, PUID xPUID, const char *xStr_KeyGenAlgorithm, const char *xStr_Name, const char *xStr_NamedCurve, size_t xsize_t_KeyLength, size_t xsize_t_RandomBits, const char *xStr_PublicExponenetLength, long long xlong_long_LifetimeInSeconds, long long xlong_long_NotBeforeWindowInSeconds, long long xlong_long_ExpiresInSecondsSinceEpoch) {}
inline void EventWriteOrtcCertificateDestroy(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcCertificateGenerated(const char *xStr_Method, PUID xPUID, bool xBool_Success) {}
inline void EventWriteOrtcCertificateFingerprint(const char *xStr_Method, PUID xPUID, const char *xStr_FingerprintAlgorithm, const char *xStr_FingerprintValue) {}

inline void EventWriteOrtcDataChannelCreate(const char *xStr_Method, PUID xPUID, PUID xPUID_DataTransport, const char *xStr_Parameters, bool xBool_Incoming, WORD xWORD_SessionID) {}
inline void EventWriteOrtcDataChannelDestroy(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcDataChannelClose(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcDataChannelCancel(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcDataChannelStep(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcDataChannelStateChangedEventFired(const char *xStr_Method, PUID xPUID, const char *xStr_State) {}
inline void EventWriteOrtcDataChannelErrorEventFired(const char *xStr_Method, PUID xPUID, WORD xWORD_Error, const char *xStr_ErrorReason) {}

inline void EventWriteOrtcDataChannelSendControlOpen(const char *xStr_Method, PUID xPUID, BYTE xBYTE_MessageType, BYTE xBYTE_ChannelType, WORD xWORD_Priority, DWORD xDWORD_ReliabilityParameter, WORD xWORD_LabelLength, WORD xWORD_ProtocolLength, const char *xStr_Label, const char *xStr_Protocol) {}
inline void EventWriteOrtcDataChannelSendControlAck(const char *xStr_Method, PUID xPUID, BYTE xBYTE_MessageType) {}

inline void EventWriteOrtcDataChannelBufferedAmountLowThresholdChanged(const char *xStr_Method, PUID xPUID, size_t xsize_t_NewThreshold, size_t xsize_t_mOldThreshold, size_t xsize_t_OutgoingBufferFillSize, bool xBool_BufferedAmountLowThresholdFired) {}

inline void EventWriteOrtcDataChannelSendString(const char *xStr_Method, PUID xPUID, const char *xStr_Data) {}
inline void EventWriteOrtcDataChannelSendBinary(const char *xStr_Method, PUID xPUID, const void *xPtr_Buffer, size_t xsize_t_BufferSizeInBytes) {}

inline void EventWriteOrtcDataChannelOutgoingBufferPacket(const char *xStr_Method, PUID xPUID, unsigned int xUInt_Type, WORD xWORD_SessionID, bool xBool_Ordered, long long xlong_long_MaxPacketLifetimeInMilliseconds, bool xBool_HasMaxRetransmits, DWORD xDWORD_MaxRetransmits, const void *xPtr_Buffer, size_t xsize_t_BufferSizeInBytes) {}
inline void EventWriteOrtcDataChannelOutgoingBufferPacketDelivered(const char *xStr_Method, PUID xPUID, unsigned int xUInt_Type, WORD xWORD_SessionID, bool xBool_Ordered, long long xlong_long_MaxPacketLifetimeInMilliseconds, bool xBool_HasMaxRetransmits, DWORD xDWORD_MaxRetransmits, const void *xPtr_Buffer, size_t xsize_t_BufferSizeInBytes) {}

inline void EventWriteOrtcDataChannelReceivedControlOpen(const char *xStr_Method, PUID xPUID, bool xBool_Incoming, BYTE xBYTE_MessageType, BYTE xBYTE_ChannelType, WORD xWORD_Priority, DWORD xDWORD_ReliabilityParameter, WORD xWORD_LabelLength, WORD xWORD_ProtocolLength, const char *xStr_Label, const char *xStr_Protocol) {}
inline void EventWriteOrtcDataChannelReceivedControlAck(const char *xStr_Method, PUID xPUID, BYTE xBYTE_MessageType) {}

inline void EventWriteOrtcDataChannelMessageFiredEvent(const char *xStr_Method, PUID xPUID, unsigned int xUInt_Type, WORD xWORD_SessionID, WORD xWORD_SequenceNumber, DWORD xDWORD_Timestamp, int xInt_Flags, const void *xPtr_Buffer, size_t xsize_t_BufferSizeInBytes) {}

inline void EventWriteOrtcDataChannelSCTPTransportDeliverOutgoingPacket(const char *xStr_Method, PUID xPUID, unsigned int xUInt_Type, WORD xWORD_SessionID, bool xBool_Ordered, long long xlong_long_MaxPacketLifetimeInMilliseconds, bool xBool_HasMaxRetransmits, DWORD xDWORD_MaxRetransmits, const void *xPtr_Buffer, size_t xsize_t_BufferSizeInBytes) {}

inline void EventWriteOrtcDataChannelSCTPTransportRequestShutdown(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcDataChannelSCTPTransportRequestNotifyClosed(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcDataChannelSCTPTransportStateChanged(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcDataChannelSCTPTransportSendReady(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcDataChannelSCTPTransportSendReadyFailure(const char *xStr_Method, PUID xPUID, WORD xWORD_Error, const char *xStr_ErrorReason) {}
inline void EventWriteOrtcDataChannelSCTPTransportReceivedIncomingPacket(const char *xStr_Method, PUID xPUID, unsigned int xUInt_Type, WORD xWORD_SessionID, WORD xWORD_SequenceNumber, DWORD xDWORD_Timestamp, int xInt_Flags, const void *xPtr_Buffer, size_t xsize_t_BufferSizeInBytes) {}

inline void EventWriteOrtcDtlsTransportCreate(const char *xStr_Method, PUID xPUID, PUID xPUID_IceTransport, const char *xStr_Component, size_t xsize_t_MaxPendingDTLSBuffer, size_t xsize_t_MaxPendingRTPPackets, size_t xsize_t_TotalCertificates) {}
inline void EventWriteOrtcDtlsTransportDestroy(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcDtlsTransportInitization(const char *xStr_Method, PUID xPUID, PUID xPUID_IceTransport, PUID xPUID_RtpListener, size_t xsize_t_TotalCiphers, size_t xsize_t_TotalFingerprints) {}
inline void EventWriteOrtcDtlsTransportStep(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcDtlsTransportCancel(const char *xStr_Method, PUID xPUID) {}

inline void EventWriteOrtcDtlsTransportInitizationInstallCipher(const char *xStr_Method, PUID xPUID, const char *xStr_Cipher) {}
inline void EventWriteOrtcDtlsTransportInitizationInstallFingerprint(const char *xStr_Method, PUID xPUID, const char *xStr_Algorithm, const char *xStr_Value, bool xBool_IsLocal) {}

inline void EventWriteOrtcDtlsTransportStart(const char *xStr_Method, PUID xPUID, const char *xStr_Role, size_t xsize_t_TotalFingerprints) {}
inline void EventWriteOrtcDtlsTransportStop(const char *xStr_Method, PUID xPUID) {}

inline void EventWriteOrtcDtlsTransportRoleSet(const char *xStr_Method, PUID xPUID, const char *xStr_Role) {}

inline void EventWriteOrtcDtlsTransportReceivedPacket(const char *xStr_Method, PUID xPUID, unsigned int xUInt_ViaTransport, bool xBool_IsDtlsPacket, const void *xPtr_Buffer, size_t xsize_t_BufferSizeInBytes) {}
inline void EventWriteOrtcDtlsTransportReceivedStunPacket(const char *xStr_Method, PUID xPUID, unsigned int xUInt_ViaTransport) {}

inline void EventWriteOrtcDtlsTransportForwardingEncryptedPacketToSrtpTransport(const char *xStr_Method, PUID xPUID, PUID xPUID_SrtpTransportObjectID, unsigned int xUInt_ViaTransport, const void *xPtr_Buffer, size_t xsize_t_BufferSizeInBytes) {}
inline void EventWriteOrtcDtlsTransportForwardingPacketToDataTransport(const char *xStr_Method, PUID xPUID, PUID xPUID_DataTransportObjectID, unsigned int xUInt_ViaTransport, const void *xPtr_Buffer, size_t xsize_t_BufferSizeInBytes) {}
inline void EventWriteOrtcDtlsTransportForwardingPacketToRtpListener(const char *xStr_Method, PUID xPUID, PUID xPUID_RtpListenerObjectID, unsigned int xUInt_ViaTransport,  unsigned int xUInt_PacketType, const void *xPtr_Buffer, size_t xsize_t_BufferSizeInBytes) {}

inline void EventWriteOrtcDtlsTransportSendRtpPacket(const char *xStr_Method, PUID xPUID, unsigned int xUInt_SendOverComponent, unsigned int xUInt_PacketType, const void *xPtr_Buffer, size_t xsize_t_BufferSizeInBytes) {}
inline void EventWriteOrtcDtlsTransportSendDataPacket(const char *xStr_Method, PUID xPUID, const void *xPtr_Buffer, size_t xsize_t_BufferSizeInBytes) {}
inline void EventWriteOrtcDtlsTransportForwardDataPacketToIceTransport(const char *xStr_Method, PUID xPUID, PUID xPUID_IceTransportObjectID, const void *xPtr_Buffer, size_t xsize_t_BufferSizeInBytes) {}

inline void EventWriteOrtcDtlsTransportSendEncryptedRtpPacket(const char *xStr_Method, PUID xPUID, PUID xPUID_IceTransportObjectID, unsigned int xUInt_SendOverComponent, unsigned int xUInt_PacketType, const void *xPtr_Buffer, size_t xsize_t_BufferSizeInBytes) {}

inline void EventWriteOrtcDtlsTransportInternalTimerEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_TimerID) {}
inline void EventWriteOrtcDtlsTransportInternalIceStateChangeEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_IceTransportObjectID, const char *xStr_State) {}
inline void EventWriteOrtcDtlsTransportInternalSrtpTransportLifetimeRemainingEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_SrtpTransportObjectID, ULONG xULONG_LeastLifetimeRemainingPercentageForAllKeys, ULONG xULONG_OverallLifetimeRemainingPercentage) {}

inline void EventWriteOrtcDtlsTransportStateChangedEventFired(const char *xStr_Method, PUID xPUID, const char *xStr_State) {}
inline void EventWriteOrtcDtlsTransportErrorEventFired(const char *xStr_Method, PUID xPUID, WORD xWORD_Error, const char *xStr_ErrorReason) {}

inline void EventWriteOrtcDtlsTransportSrtpKeyingMaterialSetup(const char *xStr_Method, PUID xPUID, PUID xPUID_SecureTransportObjectID, const char *xStr_Direction, const char *xStr_Cipher, const void *xPtr_KeyingMaterialBuffer, size_t xsize_t_KeyingMaterialBufferSizeInBytes) {}

inline void EventWriteOrtcIceGathererCreate(const char *xStr_Method, PUID xPUID, PUID xPUID_GethererRouterObjectID, const char *xStr_UsernameFragment, const char *xStr_Password, bool xBool_CreateTCPCandidates, bool xBool_ContinousGathering, size_t xsize_t_TotalInterfacePolicies, size_t xsize_t_TotalIceServers, long long xlong_long_ReflexiveInactivityTimeInSeconds, long long xlong_long_RelayInactivityTimeInSeoncds, long long xlong_long_MaxBufferingTimeInSeconds, long long xlong_long_RecheckIPsInSeconds, size_t xsize_t_MaxTotalBuffers, size_t xsize_t_MaxTCPBufferingSizePendingConnectionInBytes, size_t xsize_t_MaxTCPBufferingSizeConnectedInBytes, bool xBool_GatherPassiveTCP) {}
inline void EventWriteOrtcIceGathererDestroy(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcIceGathererStep(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcIceGathererCancel(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcIceGathererCreatedAssociateGatherer(const char *xStr_Method, PUID xPUID, PUID xPUID_AssociatedGathererObjectID) {}

inline void EventWriteOrtcIceGathererInitializeInstallInterfaceNameMapping(const char *xStr_Method, PUID xPUID, const char *xStr_InterfaceNameRegularExpresssion, const char *xStr_InterfaceType, ULONG xULONG_OrderIndex) {}
inline void EventWriteOrtcIceGathererInitializeInstallPreference(const char *xStr_Method, PUID xPUID, const char *xStr_PreferenceType, const char *xStr_Preference, const char *xStr_SubPreference, DWORD xDWORD_PreferenceValue) {}

inline void EventWriteOrtcIceGathererGather(const char *xStr_Method, PUID xPUID, bool xBool_ContinuousGathering, size_t xsize_t_TotalInterfacePolicies, size_t xsize_t_TotalIceServers) {}

inline void EventWriteOrtcIceGathererStateChangedEventFired(const char *xStr_Method, PUID xPUID, const char *xStr_State) {}
inline void EventWriteOrtcIceGathererErrorEventFired(const char *xStr_Method, PUID xPUID, WORD xWORD_Error, const char *xStr_Reason) {}

inline void EventWriteOrtcIceGathererAddCandidateEventFired(const char *xStr_Method, PUID xPUID, const char *xStr_LocalHash, const char *xStr_NotifyHash, const char *xStr_InterfaceType, const char *xStr_Foundation, DWORD xDWORD_Priority, DWORD xDWORD_UnfreezePriority, const char *xStr_Protocol, const char *xStr_IP, WORD xWORD_Port, const char *xStr_CandidateType, const char *xStr_TcpType, const char *xStr_RelatedAddress, WORD xWORD_RelatedPort) {}
inline void EventWriteOrtcIceGathererRemoveCandidateEventFired(const char *xStr_Method, PUID xPUID, const char *xStr_LocalHash, const char *xStr_NotifyHash, const char *xStr_InterfaceType, const char *xStr_Foundation, DWORD xDWORD_Priority, DWORD xDWORD_UnfreezePriority, const char *xStr_Protocol, const char *xStr_IP, WORD xWORD_Port, const char *xStr_CandidateType, const char *xStr_TcpType, const char *xStr_RelatedAddress, WORD xWORD_RelatedPort) {}
inline void EventWriteOrtcIceGathererFilterCandidateEventFired(const char *xStr_Method, PUID xPUID,  unsigned int xUInt_FilterPolicy, const char *xStr_BoundIP, const char *xStr_InterfaceType, const char *xStr_Foundation, DWORD xDWORD_Priority, DWORD xDWORD_UnfreezePriority, const char *xStr_Protocol, const char *xStr_IP, WORD xWORD_Port, const char *xStr_CandidateType, const char *xStr_TcpType, const char *xStr_RelatedAddress, WORD xWORD_RelatedPort) {}

inline void EventWriteOrtcIceGathererInstallIceTransport(const char *xStr_Method, PUID xPUID, PUID xPUID_IceTransportObjectID, const char *xStr_RemoteUsernameFragment) {}
inline void EventWriteOrtcIceGathererRemoveIceTransport(const char *xStr_Method, PUID xPUID, PUID xPUID_IceTransportObjectID) {}
inline void EventWriteOrtcIceGathererInternalIceTransportStateChangedEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_IceTransportObjectID) {}

inline void EventWriteOrtcIceGathererRemovetAllIceTransportRelatedRoutes(const char *xStr_Method, PUID xPUID, PUID xPUID_IceTransportObjectID) {}
inline void EventWriteOrtcIceGathererSendIceTransportPacket(const char *xStr_Method, PUID xPUID, PUID xPUID_IceTransportObjectID, PUID xPUID_RouteID, const void *xPtr_Buffer, size_t xsize_t_BufferSizeInBytes) {}
inline void EventWriteOrtcIceGathererSendIceTransportPacketFailed(const char *xStr_Method, PUID xPUID, PUID xPUID_IceTransportObjectID, PUID xPUID_RouteID, const void *xPtr_Buffer, size_t xsize_t_BufferSizeInBytes) {}

inline void EventWriteOrtcIceGathererSendIceTransportPacketViaUdp(const char *xStr_Method, PUID xPUID, PUID xPUID_IceTransportObjectID, PUID xPUID_RouteID, PUID xPUID_HostPortObjectID, const char *xStr_RemoteIP, const void *xPtr_Buffer, size_t xsize_t_BufferSizeInBytes) {}
inline void EventWriteOrtcIceGathererSendIceTransportPacketViaTcp(const char *xStr_Method, PUID xPUID, PUID xPUID_IceTransportObjectID, PUID xPUID_RouteID, PUID xPUID_TcpPortObjectID, const void *xPtr_Buffer, size_t xsize_t_BufferSizeInBytes) {}
inline void EventWriteOrtcIceGathererSendIceTransportPacketViaTurn(const char *xStr_Method, PUID xPUID, PUID xPUID_IceTransportObjectID, PUID xPUID_RouteID, PUID xPUID_TurnObjectID, const void *xPtr_Buffer, size_t xsize_t_BufferSizeInBytes) {}

inline void EventWriteOrtcIceGathererDeliverIceTransportIncomingPacket(const char *xStr_Method, PUID xPUID, PUID xPUID_IceTransportObjectID, PUID xPUID_RouteID, PUID xPUID_xRouterRouteID, bool xBool_WasBuffered, const void *xPtr_Buffer, size_t xsize_t_BufferSizeInBytes) {}
inline void EventWriteOrtcIceGathererBufferIceTransportIncomingPacket(const char *xStr_Method, PUID xPUID, PUID xPUID_xRouterRouteID, const void *xPtr_Buffer, size_t xsize_t_BufferSizeInBytes) {}

inline void EventWriteOrtcIceGathererDeliverIceTransportIncomingStunPacket(const char *xStr_Method, PUID xPUID, PUID xPUID_IceTransportObjectID, PUID xPUID_RouteID, PUID xPUID_xRouterRouteID, bool xBool_WasBuffered) {}
inline void EventWriteOrtcIceGathererBufferIceTransportIncomingStunPacket(const char *xStr_Method, PUID xPUID, PUID xPUID_xRouterRouteID) {}
inline void EventWriteOrtcIceGathererErrorIceTransportIncomingStunPacket(const char *xStr_Method, PUID xPUID, PUID xPUID_IceTransportObjectID, PUID xPUID_RouteID, PUID xPUID_xRouterRouteID) {}

inline void EventWriteOrtcIceGathererDisposeBufferedIceTransportIncomingPacket(const char *xStr_Method, PUID xPUID, PUID xPUID_xRouterRouteID, const void *xPtr_Buffer, size_t xsize_t_BufferSizeInBytes) {}
inline void EventWriteOrtcIceGathererDisposeBufferedIceTransportIncomingStunPacket(const char *xStr_Method, PUID xPUID, PUID xPUID_xRouterRouteID) {}

inline void EventWriteOrtcIceGathererTurnSocketReceivedPacket(const char *xStr_Method, PUID xPUID, PUID xPUID_TurnSocketObjectID, const void *xPtr_Buffer, size_t xsize_t_BufferSizeInBytes) {}
inline void EventWriteOrtcIceGathererTurnSocketSendPacket(const char *xStr_Method, PUID xPUID, PUID xPUID_TurnSocketObjectID, const void *xPtr_Buffer, size_t xsize_t_BufferSizeInBytes) {}

inline void EventWriteOrtcIceGathererInstallQuickRoute(const char *xStr_Method, PUID xPUID, const void *xPtr_Candidate, const char *xStr_IPAddress, PUID xPUID_RouteID) {}
inline void EventWriteOrtcIceGathererRemoveQuickRoute(const char *xStr_Method, PUID xPUID, const void *xPtr_Candidate, const char *xStr_IPAddress, PUID xPUID_RouteID) {}
inline void EventWriteOrtcIceGathererSearchQuickRoute(const char *xStr_Method, PUID xPUID, const void *xPtr_Candidate, const char *xStr_IPAddress, bool xBool_Found) {}

inline void EventWriteOrtcIceGathererInternalWakeEventFired(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcIceGathererInternalDnsLoookupCompleteEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_QueryID) {}
inline void EventWriteOrtcIceGathererInternalTimerEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_TimerID, const char *xStr_TimerType, PUID xPUID_RelatedObjectID) {}
inline void EventWriteOrtcIceGathererInternalLikelyReflexiveActivityEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_RouteID, PUID xPUID_xRouterRouteID) {}

inline void EventWriteOrtcIceGathererInternalSocketReadReadyEventFired(const char *xStr_Method, PUID xPUID, PUID xRelatedObjectID) {}
inline void EventWriteOrtcIceGathererInternalSocketWriteReadyEventFired(const char *xStr_Method, PUID xPUID, PUID xRelatedObjectID) {}
inline void EventWriteOrtcIceGathererInternalSocketExceptionEventFired(const char *xStr_Method, PUID xPUID, PUID xRelatedObjectID) {}

inline void EventWriteOrtcIceGathererInternalBackOffTimerStateChangedEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_BackOffTimerObjectID, const char *xStr_State) {}

inline void EventWriteOrtcIceGathererInternalStunDiscoverySendPacket(const char *xStr_Method, PUID xPUID, PUID xPUID_StunDiscoveryObjectID, const char *xStr_DestinationIP, const void *xPtr_Buffer, size_t xsize_t_BufferSizeInBytes) {}
inline void EventWriteOrtcIceGathererInternalStunDiscoveryCompleteEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_StunDiscoveryObjectID, PUID xPUID_HostPortObjectID, const char *xStr_MappedIP) {}

inline void EventWriteOrtcIceGathererInternalTurnSocketStateChangeEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_TurnSocketObjectID, const char *xStr_State) {}

inline void EventWriteOrtcIceGathererResolveHostIP(const char *xStr_Method, PUID xPUID, PUID xPUID_DnsQueryID, const char *xStr_HostName) {}
inline void EventWriteOrtcIceGathererResolveFoundHostIP(const char *xStr_Method, PUID xPUID, const char *xStr_HostIP, const char *xStr_HostName, const char *xStr_InterfaceName, ULONG xULONG_AdapterSpecific) {}

inline void EventWriteOrtcIceGathererPendingResolveHostIP(const char *xStr_Method, PUID xPUID, const char *xStr_ProfileName, const char *xStr_HostName, const char *xStr_IP) {}

inline void EventWriteOrtcIceGathererHostPortCreate(const char *xStr_Method, PUID xPUID, PUID xPUID_HostPortObjectID, const char *xStr_HostIP) {}
inline void EventWriteOrtcIceGathererHostPortDestroy(const char *xStr_Method, PUID xPUID, PUID xPUID_HostPortObjectID, const char *xStr_HostIP) {}
inline void EventWriteOrtcIceGathererHostPortBind(const char *xStr_Method, PUID xPUID, PUID xPUID_HostPortObjectID, const char *xStr_HostIP, const char *Str_ProtocolType, bool xBool_Success) {}
inline void EventWriteOrtcIceGathererHostPortClose(const char *xStr_Method, PUID xPUID, PUID xPUID_HostPortObjectID, const char *xStr_HostIP, const char *Str_ProtocolType) {}

inline void EventWriteOrtcIceGathererReflexivePortCreate(const char *xStr_Method, PUID xPUID, PUID xPUID_ReflexivePortObjectID, const char *xStr_Server) {}
inline void EventWriteOrtcIceGathererReflexivePortDestroy(const char *xStr_Method, PUID xPUID, PUID xPUID_ReflexivePortObjectID, const char *xStr_Server) {}
inline void EventWriteOrtcIceGathererReflexivePortFoundMapped(const char *xStr_Method, PUID xPUID, PUID xPUID_ReflexivePortObjectID, const char *xStr_MappedIP) {}

inline void EventWriteOrtcIceGathererRelayPortCreate(const char *xStr_Method, PUID xPUID, PUID xPUID_RelayPortObjectID, const char *xStr_Server, const char *xStr_Username, const char *xStr_Credential, const char *xStr_CredentialType) {}
inline void EventWriteOrtcIceGathererRelayPortDestroy(const char *xStr_Method, PUID xPUID, PUID xPUID_RelayPortObjectID, const char *xStr_Server) {}
inline void EventWriteOrtcIceGathererRelayPortFoundIP(const char *xStr_Method, PUID xPUID, PUID xPUID_RelayPortObjectID, const char *xStr_CandidateType, const char *xStr_IP) {}

inline void EventWriteOrtcIceGathererTcpPortCreate(const char *xStr_Method, PUID xPUID, PUID xPUID_TcpPortObjectID, const char *xStr_RemoteIP) {}
inline void EventWriteOrtcIceGathererTcpPortDestroy(const char *xStr_Method, PUID xPUID, PUID xPUID_TcpPortObjectID, const char *xStr_RemoteIP) {}

inline void EventWriteOrtcIceGathererUdpSocketPacketReceivedFrom(const char *xStr_Method, PUID xPUID, const char *xStr_FromIP, const void *xPtr_Buffer, size_t xsize_t_BufferSizeInBytes) {}
inline void EventWriteOrtcIceGathererUdpSocketPacketForwardingToTurnSocket(const char *xStr_Method, PUID xPUID, const char *xStr_FromIP, bool xBool_IsStun, const void *xPtr_Buffer, size_t xsize_t_BufferSizeInBytes) {}
inline void EventWriteOrtcIceGathererUdpSocketPacketSentTo(const char *xStr_Method, PUID xPUID, const char *xStr_BoundIP, const char *xStr_ToIP, const void *xPtr_Buffer, size_t xsize_t_BufferSizeInBytes) {}

inline void EventWriteOrtcIceGathererTcpSocketPacketReceivedFrom(const char *xStr_Method, PUID xPUID, const char *xStr_FromIP, const void *xPtr_Buffer, size_t xsize_t_BufferSizeInBytes) {}
inline void EventWriteOrtcIceGathererTcpSocketSentOutgoing(const char *xStr_Method, PUID xPUID, const char *xStr_FromIP, const void *xPtr_Buffer, size_t xsize_t_BufferSizeInBytes) {}

inline void EventWriteOrtcIceGathererRouteTrace(const char *xStr_Method, const char *xStr_CallingMethod, const char *xStr_Message, PUID xGathererRouteObjectID, PUID xPUID_GathererObjectID, long long xlong_long_LastUsedInMillisecondsSinceEpoch, PUID xPUID_IceTransportObjectID, PUID xPUID_HostPortObjectID, PUID xPUID_RelayPortObjectID, PUID xPUID_TcpPortObjectID, const char *xStr_LocalInterfaceType, const char *xStr_LocalFoundation, DWORD xDWORD_LocalPriority, DWORD xDWORD_LocalUnfreezePriority, const char *xStr_LocalProtocol, const char *xStr_LocalIP, WORD xWORD_LocalPort, const char *xStr_LocalCandidateType, const char *xStr_LocalTcpType, const char *xStr_LocalRelatedAddress, WORD xWORD_LocalRelatedPort) {}

inline void EventWriteOrtcIceGathererRouterCreate(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcIceGathererRouterDestroy(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcIceGathererRouterCancel(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcIceGathererRouterInternalEvent(const char *xStr_Method, PUID xPUID, const char *xStr_Event, const char *xStr_CandidateHash, const char *xStr_LocalCandidateIP, WORD xWORD_LocalCandidatePort, const char *xStr_RemoteIP) {}

inline void EventWriteOrtcIceGathererRouterRouteTrace(const char *xStr_Method, const char *xStr_CallingMethod, const char *xStr_Message, PUID xGathererRouterRouteObjectID, const char *xStr_LocalInterfaceType, const char *xStr_LocalFoundation, DWORD xDWORD_LocalPriority, DWORD xDWORD_LocalUnfreezePriority, const char *xStr_LocalProtocol, const char *xStr_LocalIP, WORD xWORD_LocalPort, const char *xStr_LocalCandidateType, const char *xStr_LocalTcpType, const char *xStr_LocalRelatedAddress, WORD xWORD_LocalRelatedPort, const char *xStr_RemoteIP) {}

inline void EventWriteOrtcIceTransportCreate(const char *xStr_Method, PUID xPUID, PUID xPUID_GathererObjectID, PUID xPUID_GathererRouterObjectID, long long xlong_long_NoPacketReceivedRecheckTimeInSeconds, long long xlong_long_ExpireRouteInSeconds, bool xBool_TestLowerPreferenceCandidatePairs, bool xBool_BlacklistConsent, long long xlong_long_KeepWarmTimeBaseInMilliseconds, long long xlong_long_KeepWarmTimeRandomAddTimeInMilliseconds, size_t xsize_t_MaxBufferedPackets, QWORD xQWORD_ConflictResolver) {}
inline void EventWriteOrtcIceTransportDestroy(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcIceTransportStep(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcIceTransportCancel(const char *xStr_Method, PUID xPUID) {}

inline void EventWriteOrtcIceTransportRouteStateTrackerStateCountChange(const char *xStr_Method, PUID xPUID_IceTransportObjectID, const char *xStr_State, size_t xsize_t_Value) {}

inline void EventWriteOrtcIceTransportStart(const char *xStr_Method, PUID xPUID, PUID xPUID_GathererObjectID, bool xBool_RemoteUseCandidateFreezePriority, const char *xStr_RemoteUsernameFragment, const char *xStr_RemotePassword, bool xBool_IceLite, const char *xStr_RemoteParametersHash, const char *xStr_OldRemoteParametersHash, bool xBool_HasRemoteUsernameFragment) {}
inline void EventWriteOrtcIceTransportCreateAssociatedTransport(const char *xStr_Method, PUID xPUID, PUID xPUID_AssociatedTransportObjectID) {}

inline void EventWriteOrtcIceTransportAddRemoteCandidate(const char *xStr_Method, PUID xPUID, const char *xStr_Hash, const char *xStr_InterfaceType, const char *xStr_Foundation, DWORD xDWORD_Priority, DWORD xDWORD_UnfreezePriority, const char *xStr_Protocol, const char *xStr_IP, WORD xWORD_Port, const char *xStr_CandidateType, const char *xStr_TcpType, const char *xStr_RelatedAddress, WORD xWORD_RelatedPort, bool xBool_PreviouslyAdded) {}
inline void EventWriteOrtcIceTransportAddRemoteCandidateComplete(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcIceTransportRemoveRemoteCandidate(const char *xStr_Method, PUID xPUID, const char *xStr_Hash, const char *xStr_InterfaceType, const char *xStr_Foundation, DWORD xDWORD_Priority, DWORD xDWORD_UnfreezePriority, const char *xStr_Protocol, const char *xStr_IP, WORD xWORD_Port, const char *xStr_CandidateType, const char *xStr_TcpType, const char *xStr_RelatedAddress, WORD xWORD_RelatedPort, bool xBool_WasKnownPreviously) {}
inline void EventWriteOrtcIceTransportRemoveRemoteCandidateComplete(const char *xStr_Method, PUID xPUID) {}

inline void EventWriteOrtcIceTransportKeepWarm(const char *xStr_Method, PUID xPUID, const char *xStr_Reason, const char *xStr_CandidatePairHash, bool xBool_KeepWarm) {}

inline void EventWriteOrtcIceTransportStateChangedEventFired(const char *xStr_Method, PUID xPUID, const char *xStr_State) {}
inline void EventWriteOrtcIceTransportErrorEventFired(const char *xStr_Method, PUID xPUID, WORD xWORD_Error, const char *xStr_State) {}
inline void EventWriteOrtcIceTransportCandidatePairChangedEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_RouteObjectID) {}

inline void EventWriteOrtcIceTransportRouteTrace(const char *xStr_Method, const char *xStr_CallingMethod, const char *xStr_Message, PUID xIceTransportRouteObjectID, PUID xPUID_IceTransportObjectID, const char *xStr_CandidatePairHash, const char *xStr_LocalInterfaceType, const char *xStr_LocalFoundation, DWORD xDWORD_LocalPriority, DWORD xDWORD_LocalUnfreezePriority, const char *xStr_LocalProtocol, const char *xStr_LocalIP, WORD xWORD_LocalPort, const char *xStr_LocalCandidateType, const char *xStr_LocalTcpType, const char *xStr_LocalRelatedAddress, WORD xWORD_LocalRelatedPort, const char *xStr_RemoteInterfaceType, const char *xStr_RemoteFoundation, DWORD xDWORD_RemotePriority, DWORD xDWORD_RemoteUnfreezePriority, const char *xStr_RemoteProtocol, const char *xStr_RemoteIP, WORD xWORD_RemotePort, const char *xStr_RemoteCandidateType, const char *xStr_RemoteTcpType, const char *xStr_RemoteRelatedAddress, WORD xWORD_RemoteRelatedPort, PUID xPUID_GathererRouteObjectID, QWORD xQWORD_PendingPriority, long long xlong_long_LastReceivedCheckTimeInMillisecondsSinceEpoch, long long xlong_long_LastSentCheckTimeInMillisecondsSinceEpoch, long long xlong_long_LastReceivedMediaTimeInMillisecondsSinceEpoch, long long xlong_long_LastReceivedResponseTimeInMillisecondsSinceEpoch, bool xBool_Prune, bool xBool_KeepWarm, PUID xPUID_OutgoingCheckStunRequesterObjectID, PUID xPUID_NextKeepWarmTimerObjectID, bool xBool_FrozenPromise, size_t xsize_t_TotalDependentPromises, long long xlong_long_LastRoundTripCheckInMillisecondsSinceEpoch, long long xlong_long_LastRoundTripMeasurementInMilliseconds) {}

inline void EventWriteOrtcIceTransportReceivedPacketFromGatherer(const char *xStr_Method, PUID xPUID, PUID xPUID_RouterRouteObjectID, const void *xPtr_Buffer, size_t xsize_t_BufferSizeInBytes) {}
inline void EventWriteOrtcIceTransportReceivedStunPacketFromGatherer(const char *xStr_Method, PUID xPUID, PUID xPUID_RouterRouteObjectID) {}
inline void EventWriteOrtcIceTransportRetryReceivedStunPacketFromGatherer(const char *xStr_Method, PUID xPUID, PUID xPUID_RouterRouteObjectID) {}

inline void EventWriteOrtcIceTransportBufferingIncomingPacket(const char *xStr_Method, PUID xPUID, const void *xPtr_Buffer, size_t xsize_t_BufferSizeInBytes) {}
inline void EventWriteOrtcIceTransportDisposingBufferedIncomingPacket(const char *xStr_Method, PUID xPUID, const void *xPtr_Buffer, size_t xsize_t_BufferSizeInBytes) {}
inline void EventWriteOrtcIceTransportDeliveringBufferedIncomingPacketToSecureTransport(const char *xStr_Method, PUID xPUID, PUID xPUID_SecureTransportObjectID, const void *xPtr_Buffer, size_t xsize_t_BufferSizeInBytes) {}

inline void EventWriteOrtcIceTransportDeliveringIncomingPacketToSecureTransport(const char *xStr_Method, PUID xPUID, PUID xPUID_SecureTransportObjectID, const void *xPtr_Buffer, size_t xsize_t_BufferSizeInBytes) {}
inline void EventWriteOrtcIceTransportDeliveringIncomingStunPacketToSecureTransport(const char *xStr_Method, PUID xPUID, PUID xPUID_SecureTransportObjectID) {}

inline void EventWriteOrtcIceTransportInstallFoundation(const char *xStr_Method, PUID xPUID, const char *xStr_LocalFoundation, const char *xStr_RemoteFoundation, size_t xsize_t_TotalRoutes) {}
inline void EventWriteOrtcIceTransportRemoveFoundation(const char *xStr_Method, PUID xPUID, const char *xStr_LocalFoundation, const char *xStr_RemoteFoundation, size_t xsize_t_TotalRoutes) {}
inline void EventWriteOrtcIceTransportInstallFoundationDependencyFreezePromise(const char *xStr_Method, PUID xPUID, const char *xStr_LocalFoundation, const char *xStr_RemoteFoundation) {}

inline void EventWriteOrtcIceTransportSecureTransportSendPacket(const char *xStr_Method, PUID xPUID, const void *xPtr_Buffer, size_t xsize_t_BufferSizeInBytes) {}
inline void EventWriteOrtcIceTransportForwardSecureTransportPacketToGatherer(const char *xStr_Method, PUID xPUID, PUID xPUID_GathererObjectID, const void *xPtr_Buffer, size_t xsize_t_BufferSizeInBytes) {}

inline void EventWriteOrtcIceTransportSendStunPacket(const char *xStr_Method, PUID xPUID, PUID xPUID_GathererObjectID, const void *xPtr_Buffer, size_t xsize_t_BufferSizeInBytes) {}

inline void EventWriteOrtcIceTransportInternalControllerAttachedEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_IceTransportControllerObjectID) {}
inline void EventWriteOrtcIceTransportInternalControllerDetachedEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_IceTransportControllerObjectID) {}

inline void EventWriteOrtcIceTransportInternalSecureTransportAttachedEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_SecureTransportObjectID) {}
inline void EventWriteOrtcIceTransportInternalSecureTransportDetachedEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_SecureTransportObjectID) {}

inline void EventWriteOrtcIceTransportInternalWarmRoutesChangedEventFired(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcIceTransportInternalDeliveryPendingPacketsEventFired(const char *xStr_Method, PUID xPUID) {}

inline void EventWriteOrtcIceTransportInternalWakeEventFired(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcIceTransportInternalTimerEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_TimerID, const char *xStr_TimerType) {}

inline void EventWriteOrtcIceTransportInternalUnfrozenPromiseEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_RouteObjectID) {}

inline void EventWriteOrtcIceTransportInternalGathererStateChangedEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_GathererObjectID, const char *xStr_State) {}
inline void EventWriteOrtcIceTransportInternalGathererAddLocalCandidateEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_GathererObjectID, const char *xStr_InterfaceType, const char *xStr_Foundation, DWORD xDWORD_Priority, DWORD xDWORD_UnfreezePriority, const char *xStr_Protocol, const char *xStr_IP, WORD xWORD_Port, const char *xStr_CandidateType, const char *xStr_TcpType, const char *xStr_RelatedAddress, WORD xWORD_RelatedPort) {}
inline void EventWriteOrtcIceTransportInternalGathererAddLocalCandidateCompleteEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_GathererObjectID) {}
inline void EventWriteOrtcIceTransportInternalGathererRemoveLocalCandidateEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_GathererObjectID, const char *xStr_InterfaceType, const char *xStr_Foundation, DWORD xDWORD_Priority, DWORD xDWORD_UnfreezePriority, const char *xStr_Protocol, const char *xStr_IP, WORD xWORD_Port, const char *xStr_CandidateType, const char *xStr_TcpType, const char *xStr_RelatedAddress, WORD xWORD_RelatedPort) {}

inline void EventWriteOrtcIceTransportInternalStunRequesterCreate(const char *xStr_Method, PUID xPUID, PUID xPUID_StunRequesterObjectID) {}
inline void EventWriteOrtcIceTransportInternalStunRequesterSendPacket(const char *xStr_Method, PUID xPUID, PUID xPUID_StunRequesterObjectID, const char *xStr_DestinationIP, const void *xPtr_Buffer, size_t xsize_t_BufferSizeInBytes) {}
inline void EventWriteOrtcIceTransportInternalStunRequesterReceivedResponse(const char *xStr_Method, PUID xPUID, PUID xPUID_StunRequesterObjectID, const char *xStr_FromIP) {}
inline void EventWriteOrtcIceTransportInternalStunRequesterReceivedResponseMismatch(const char *xStr_Method, PUID xPUID, PUID xPUID_StunRequesterObjectID, const char *xStr_FromIP, const char *xStr_ExpectingIP) {}
inline void EventWriteOrtcIceTransportInternalStunRequesterTimedOut(const char *xStr_Method, PUID xPUID, PUID xPUID_StunRequesterObjectID) {}

inline void EventWriteOrtcIceTransportInternalRoleConflictDetectedEventFired(const char *xStr_Method, PUID xPUID, const char *xStr_NewRole, const char *xStr_Reason) {}

inline void EventWriteOrtcIceTransportControllerCreate(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcIceTransportControllerDestroy(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcIceTransportControllerCancel(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcIceTransportControllerStep(const char *xStr_Method, PUID xPUID) {}

inline void EventWriteOrtcIceTransportControllerInternalWakeEventFired(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcIceTransportControllerInternalTransportAttachedEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_IceTransportObjectID, size_t xsize_t_AttachedOrderID, bool xBool_HasInsertIndex, size_t xsize_t_InsertIndex) {}
inline void EventWriteOrtcIceTransportControllerInternalTransportDetachedEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_IceTransportObjectID, size_t xsize_t_DetachedOrderID) {}

inline void EventWriteOrtcIceTransportControllerWaitUntilUnfrozen(const char *xStr_Method, PUID xPUID, PUID xPUID_IceTransportObjectID, const char *xStr_LocalFoundation, const char *xStr_RemoteFoundation) {}
inline void EventWriteOrtcIceTransportControllerNoNeedToWaitUntilUnfrozen(const char *xStr_Method, PUID xPUID, PUID xPUID_IceTransportObjectID, const char *xStr_LocalFoundation, const char *xStr_RemoteFoundation) {}

inline void EventWriteOrtcRtpListenerCreate(const char *xStr_Method, PUID xPUID, PUID xPUID_RtpTransport, size_t xsize_t_MaxBufferedRtpPackets, long long xlong_long_MaxRtpPacketAgeInSeconds, size_t xsize_t_MaxBufferedRtcpPackets, long long xlong_long_AmbigousPayloadMappingMinDifferenceInMilliseconds, long long xlong_long_SsrcTableExpiresInSeconds, long long xlong_long_UnhandledEventsExpiresInSeconds) {}
inline void EventWriteOrtcRtpListenerDestroy(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcRtpListenerCancel(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcRtpListenerStep(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcRtpListenerFindMapping(const char *xStr_Method, PUID xPUID, const char *xStr_MuxID, const void *xPtr_Buffer, size_t xsize_t_BufferSizeInBytes) {}
inline void EventWriteOrtcRtpListenerFoundMappingByMuxID(const char *xStr_Method, PUID xPUID, PUID xPUID_RtpReceiverObjectID, const char *xStr_MuxID) {}
inline void EventWriteOrtcRtpListenerFoundMappingBySsrc(const char *xStr_Method, PUID xPUID, PUID xPUID_RtpReceiverObjectID, DWORD xDWORD_Ssrc) {}
inline void EventWriteOrtcRtpListenerFoundMappingByPayloadType(const char *xStr_Method, PUID xPUID, PUID xPUID_RtpReceiverObjectID, BYTE xBYTE_PayloadType) {}

inline void EventWriteOrtcRtpListenerStateChangedEventFired(const char *xStr_Method, PUID xPUID, const char *xStr_State) {}
inline void EventWriteOrtcRtpListenerErrorEventFired(const char *xStr_Method, PUID xPUID, WORD xWORD_ErrorCode, const char *xStr_ErrorReason) {}
inline void EventWriteOrtcRtpListenerUnhandledEventFired(const char *xStr_Method, PUID xPUID, const char *xStr_MuxID, const char *xStr_Rid, DWORD xDWORD_Ssrc, BYTE xBYTE_PayloadType) {}

inline void EventWriteOrtcRtpListenerRegisterHeaderExtension(const char *xStr_Method, PUID xPUID, PUID xPUID_RegisterForObject, const char *xStr_ExtensionURI, unsigned short xunsigned_short_LocalID, bool xBool_Encrypted, size_t xsize_t_TotalReferences) {}
inline void EventWriteOrtcRtpListenerUnregisterHeaderExtension(const char *xStr_Method, PUID xPUID, PUID xPUID_RegisterForObject, const char *xStr_ExtensionURI, unsigned short xunsigned_short_LocalID, bool xBool_Encrypted, size_t xsize_t_TotalReferences) {}

inline void EventWriteOrtcRtpListenerReceivedIncomingPacket(const char *xStr_Method, PUID xPUID, unsigned int xUInt_ViaComponent, unsigned int xUInt_PacketType, const void *xPtr_Buffer, size_t xsize_t_BufferSizeInBytes) {}
inline void EventWriteOrtcRtpListenerBufferIncomingPacket(const char *xStr_Method, PUID xPUID, unsigned int xUInt_ViaComponent, unsigned int xUInt_PacketType, const void *xPtr_Buffer, size_t xsize_t_BufferSizeInBytes) {}
inline void EventWriteOrtcRtpListenerForwardIncomingPacket(const char *xStr_Method, PUID xPUID, PUID xPUID_SenderOrReceiverObjectID, unsigned int xUInt_ViaComponent, unsigned int xUInt_PacketType, const void *xPtr_Buffer, size_t xsize_t_BufferSizeInBytes) {}
inline void EventWriteOrtcRtpListenerDisposeBufferedIncomingPacket(const char *xStr_Method, PUID xPUID, unsigned int xUInt_PacketType, const void *xPtr_Buffer, size_t xsize_t_BufferSizeInBytes) {}

inline void EventWriteOrtcRtpListenerRegisterReceiver(const char *xStr_Method, PUID xPUID, PUID xPUID_RtpReceiverObjectID, PUID xPUID_OrderID, const char *xStr_Kind) {}
inline void EventWriteOrtcRtpListenerUnregisterReceiver(const char *xStr_Method, PUID xPUID, PUID xPUID_RtpReceiverObjectID) {}

inline void EventWriteOrtcRtpListenerRegisterSender(const char *xStr_Method, PUID xPUID, PUID xPUID_RtpSenderObjectID) {}
inline void EventWriteOrtcRtpListenerUnregisterSender(const char *xStr_Method, PUID xPUID, PUID xPUID_RtpSenderObjectID) {}

inline void EventWriteOrtcRtpListenerInternalWakeEventFired(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcRtpListenerInternalTimerEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_TimerID, const char *xStr_TimerType) {}

inline void EventWriteOrtcRtpListenerSsrcTableEntryAdded(const char *xStr_Method, PUID xPUID, PUID xPUID_RtpReceiverObjectID, DWORD xDWORD_Ssrc, long long xlong_long_LastUsageSinceEpochInSeconds, const char *xStr_MuxID) {}
inline void EventWriteOrtcRtpListenerSsrcTableEntryRemoved(const char *xStr_Method, PUID xPUID, PUID xPUID_RtpReceiverObjectID, DWORD xDWORD_Ssrc, long long xlong_long_LastUsageSinceEpochInSeconds, const char *xStr_MuxID, const char *xStr_Reason) {}
inline void EventWriteOrtcRtpListenerSsrcTableEntryUpdated(const char *xStr_Method, PUID xPUID, PUID xPUID_RtpReceiverObjectID, DWORD xDWORD_Ssrc, long long xlong_long_LastUsageSinceEpochInSeconds, const char *xStr_MuxID) {}

}
#endif //ndef ORTC_USE_NOOP_EVENT_TRACE_MACROS

#endif //USE_ETW
