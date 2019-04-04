#pragma once
// ---- �����Ľ����� ---- //
#include "CTP_API/ThostFtdcTraderApi.h"
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>
#include "iostream"
#include <iostream> 
#include <windows.h>
#include <vector>

class CustomTradeSpi : public CThostFtdcTraderSpi
{
// ---- ctp_api���ֻص��ӿ� ---- //
public:
	///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
	void OnFrontConnected();

	///��¼������Ӧ
	void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///����Ӧ��
	void OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ���������
	void OnFrontDisconnected(int nReason);

	///������ʱ���档����ʱ��δ�յ�����ʱ���÷��������á�
	void OnHeartBeatWarning(int nTimeLapse);

	///�ǳ�������Ӧ
	void OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///Ͷ���߽�����ȷ����Ӧ
	void OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ��Լ��Ӧ
	void OnRspQryInstrument(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ�ʽ��˻���Ӧ
	void OnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯͶ���ֲ߳���Ӧ
	void OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///����¼��������Ӧ
	void OnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///��������������Ӧ
	void OnRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///����֪ͨ
	void OnRtnOrder(CThostFtdcOrderField *pOrder);

	///�ɽ�֪ͨ
	void OnRtnTrade(CThostFtdcTradeField *pTrade);
	
// ---- �Զ��庯�� ---- //
public:
	bool loginFlag; // ��½�ɹ��ı�ʶ
	// ��������
	int iOrderRef;
	int iRequestID;

	// ���гɹ�������¼
	std::map<char *, int> tradeOrderRefs;

	//int FRONT_ID;
	//int SESSION_ID;

	void reqOrderInsert(
		TThostFtdcInstrumentIDType instrumentID,
		TThostFtdcPriceType price,
		TThostFtdcVolumeType volume,
		TThostFtdcDirectionType direction); // ���Ի�����¼�룬�ⲿ����
	//
	int InsertOrder(char *InstrumentID, TThostFtdcDirectionType dir, char offsetFlag, char priceType, double price, int num);
	//
	int DeleteOrder(char *InstrumentID, int orderRef);

	void CallBackCloseOrder(bool flag, int iOrderRef);

	void reqUserLogin(); // ��¼����
	void reqUserLogout(); // �ǳ�����
	void reqSettlementInfoConfirm(); // Ͷ���߽��ȷ��
	void reqQueryInstrument(); // �����ѯ��Լ
	void reqQueryTradingAccount(); // �����ѯ�ʽ��ʻ�
	void reqQueryInvestorPosition(); // �����ѯͶ���ֲ߳�
	void reqOrderInsert(); // ���󱨵�¼��
	
	void reqOrderAction(CThostFtdcOrderField *pOrder); // ���󱨵�����
	bool isErrorRspInfo(CThostFtdcRspInfoField *pRspInfo); // �Ƿ��յ�������Ϣ
	bool isMyOrder(CThostFtdcOrderField *pOrder); // �Ƿ��ҵı����ر�
	bool isTradingOrder(CThostFtdcOrderField *pOrder); // �Ƿ����ڽ��׵ı���
};