#pragma once

/*! \class FrameBuffer
*	\brief OpenGL ������ ���۸� ǥ���ϴ� Ŭ����
*
*	\author ������(shyun@dongguk.edu)
*	\date	2023-12-02
*/
class FrameBuffer
{
public:
	/*! \biref ������ ���� �ʺ� */
	int m_Width;

	/*! \biref ������ ���� ���� */
	int m_Height;

	/*! \biref ������ ���� ��ü �ڵ� */
	unsigned int m_FrameBufObj;

	/*! \biref ������ �ؽ�ó ���̵� */
	unsigned int m_Texture;

	/*! \biref ������ ���� ��ü �ڵ� */
	unsigned int m_RenderBufObj;

public:
	/*! \biref ������ */
	FrameBuffer(int width = 500, int height = 500);

	/*! \biref �Ҹ��� */
	~FrameBuffer();

	/*!
	*	\biref	������ �ؽ�ó�� ��ȯ�Ѵ�.
	*
	*	\return	������ �ؽ�ó�� ��ȯ�Ѵ�.
	*/
	unsigned int GetFrameTexture();

	/*!
	*	\biref	������ ������ ũ�⸦ �缳���Ѵ�.
	*
	*	\param	width[in]	������ �ʺ�
	*	\param	height[in]	������ ����
	*/
	void RescaleFrameBuffer(int width, int height);

	/*!
	*	\biref	������ ���۸� ���ε��Ѵ�.
	*/
	void Bind() const;

	/*!
	*	\biref	������ ���۸� ����ε��Ѵ�.
	*/
	void Unbind() const;
};

/*! \class	Camera
*	\brief	ȭ�� ������ ���� Ŭ����
*
*	\author ������(shyun@dongguk.edu)
*	\date	2023-12-17
*/
class Camera
{
public:
	/*! \brief Ʈ���� ȭ���� �ʺ� */
	int m_Width;

	/*! \brief Ʈ���� ȭ���� ���� */
	int m_Height;

	/*! \brief Ʈ���� ȸ���� */
	float m_Axis[3];

	/*! \brief ȸ�� ���� */
	float m_Angle;

	/*! \brief ���� ȸ����� */
	float m_RotMat[16];

	/*! \brief ����(�ƿ�)�� �����ϴ� ���� */
	float m_Zoom;

	/*! \brief Panning ���� */
	float m_Pan[3];

	/*! \brief ���콺 Ŭ�� ��ġ */
	int m_StartPt[2];

	/*! \brief GL 2���� ��ü ������ */
	GLUquadric* m_pObj;

public:
	/*! \brief ������ */
	Camera();

	/*! \brief �Ҹ��� */
	~Camera();

	void Reset();
	void SetWindowSize(int width, int height);
	void ProcessMouseEvents();
	void SetupViewFrustum();
	void SetupViewTransform();
	void GetSphereCoord(int x, int y, float* px, float* py, float* pz);
};
