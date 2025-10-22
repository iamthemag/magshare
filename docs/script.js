// Hamburger Menu Toggle
const hamburger = document.getElementById('hamburger');
const navMenu = document.getElementById('navMenu');

hamburger.addEventListener('click', () => {
    hamburger.classList.toggle('active');
    navMenu.classList.toggle('active');
});

// Close menu when clicking on a link
navMenu.querySelectorAll('a').forEach(link => {
    link.addEventListener('click', () => {
        hamburger.classList.remove('active');
        navMenu.classList.remove('active');
    });
});

// Close menu when clicking outside
document.addEventListener('click', (event) => {
    const isClickInsideNav = navMenu.contains(event.target);
    const isClickOnHamburger = hamburger.contains(event.target);
    
    if (!isClickInsideNav && !isClickOnHamburger && navMenu.classList.contains('active')) {
        hamburger.classList.remove('active');
        navMenu.classList.remove('active');
    }
});

// Fetch Latest Release from GitHub
const GITHUB_API_URL = 'https://api.github.com/repos/iamthemag/magshare/releases/latest';

async function fetchLatestRelease() {
    try {
        const response = await fetch(GITHUB_API_URL);
        
        if (!response.ok) {
            throw new Error('Failed to fetch release data');
        }
        
        const data = await response.json();
        return data;
    } catch (error) {
        console.error('Error fetching release:', error);
        return null;
    }
}

function findAssetByPlatform(assets, platform) {
    const patterns = {
        windows: /\.exe$/i,
        linux: /\.deb$/i,
        macos: /\.dmg$/i
    };
    
    const pattern = patterns[platform];
    if (!pattern) return null;
    
    return assets.find(asset => pattern.test(asset.name));
}

function updateDownloadButtons(releaseData) {
    const versionElement = document.getElementById('latestVersion');
    const downloadButtons = document.querySelectorAll('.btn-download');
    
    if (!releaseData) {
        versionElement.textContent = 'Unable to load';
        downloadButtons.forEach(btn => {
            btn.disabled = true;
            btn.querySelector('.btn-text').textContent = 'Unavailable';
        });
        return;
    }
    
    // Update version display
    versionElement.textContent = releaseData.tag_name;
    
    // Update download buttons
    downloadButtons.forEach(btn => {
        const platform = btn.dataset.platform;
        const asset = findAssetByPlatform(releaseData.assets, platform);
        
        btn.classList.remove('loading');
        
        if (asset) {
            btn.addEventListener('click', () => {
                window.open(asset.browser_download_url, '_blank');
            });
        } else {
            // If no asset found, link to releases page
            btn.addEventListener('click', () => {
                window.open(releaseData.html_url, '_blank');
            });
            
            // Update button text to indicate manual download
            const buttonText = btn.querySelector('.btn-text');
            if (platform === 'windows') {
                buttonText.textContent = 'View Release';
            } else if (platform === 'linux') {
                buttonText.textContent = 'View Release';
            } else if (platform === 'macos') {
                buttonText.textContent = 'View Release';
            }
        }
    });
}

// Initialize download buttons as loading
function initializeDownloadButtons() {
    const downloadButtons = document.querySelectorAll('.btn-download');
    downloadButtons.forEach(btn => {
        btn.classList.add('loading');
    });
}

// Load release data on page load
document.addEventListener('DOMContentLoaded', async () => {
    initializeDownloadButtons();
    const releaseData = await fetchLatestRelease();
    updateDownloadButtons(releaseData);
});

// Smooth scroll for anchor links
document.querySelectorAll('a[href^="#"]').forEach(anchor => {
    anchor.addEventListener('click', function (e) {
        const href = this.getAttribute('href');
        
        // Skip if it's just "#"
        if (href === '#') return;
        
        e.preventDefault();
        const target = document.querySelector(href);
        
        if (target) {
            target.scrollIntoView({
                behavior: 'smooth',
                block: 'start'
            });
        }
    });
});

// Add scroll effect to navbar
let lastScroll = 0;
const navbar = document.querySelector('.navbar');

window.addEventListener('scroll', () => {
    const currentScroll = window.pageYOffset;
    
    if (currentScroll <= 0) {
        navbar.style.boxShadow = '0 2px 10px rgba(0, 0, 0, 0.1)';
    } else {
        navbar.style.boxShadow = '0 2px 20px rgba(0, 0, 0, 0.15)';
    }
    
    lastScroll = currentScroll;
});

// Fallback: If no releases are found, show manual download option
function showManualDownloadFallback() {
    const versionElement = document.getElementById('latestVersion');
    const downloadGrid = document.getElementById('downloadGrid');
    
    versionElement.textContent = 'Not Available';
    
    downloadGrid.innerHTML = `
        <div class="download-card" style="grid-column: 1 / -1;">
            <h3>Download from GitHub</h3>
            <p>Visit our GitHub releases page to download the latest version</p>
            <a href="https://github.com/iamthemag/magshare/releases" target="_blank" class="btn btn-primary">
                Go to Releases
            </a>
        </div>
    `;
}

// Optional: Add intersection observer for animations
const observerOptions = {
    threshold: 0.1,
    rootMargin: '0px 0px -100px 0px'
};

const observer = new IntersectionObserver((entries) => {
    entries.forEach(entry => {
        if (entry.isIntersecting) {
            entry.target.style.opacity = '1';
            entry.target.style.transform = 'translateY(0)';
        }
    });
}, observerOptions);

// Observe feature cards for fade-in animation
document.addEventListener('DOMContentLoaded', () => {
    const cards = document.querySelectorAll('.feature-card, .download-card');
    cards.forEach(card => {
        card.style.opacity = '0';
        card.style.transform = 'translateY(20px)';
        card.style.transition = 'opacity 0.6s ease, transform 0.6s ease';
        observer.observe(card);
    });
});
